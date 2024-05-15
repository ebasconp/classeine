#pragma once

#include <string>
#include <unordered_map>
#include <variant>

namespace clsn::core
{
    using ConfigurationValueTypes =
        std::variant<bool, int, double, std::string>;

    using SectionMap = std::unordered_map<std::string, ConfigurationValueTypes>;

    class Configuration final
    {
    public:
        Configuration() = default;
        ~Configuration() = default;

    private:
        std::unordered_map<std::string, SectionMap> m_sections;

    public:
        template <typename ValueType>
        void set(const std::string& sectionName, const std::string& key,
                 ValueType&& value)
        {
            m_sections[sectionName][key] = std::forward<ValueType>(value);
        }

        template <typename ValueType>
        const ValueType& getOrDefault(
                    const std::string& sectionName,
                    const std::string& key,
                    const ValueType& defaultValue)
        {
            auto sectionIt = m_sections.find(sectionName);
            if (sectionIt == m_sections.end())
                return defaultValue;

            auto& sectionMap = sectionIt->second;
            auto it = sectionMap.find(key);
            if (it == sectionMap.end())
                return defaultValue;

            const auto* value = std::get_if<ValueType>(it->second);
            return value ? *value : defaultValue;
        }
    };
}