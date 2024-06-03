#pragma once

#include <functional>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>

namespace clsn::core
{
    template <typename... ConfigurationValueTypes>
    class Configuration final
    {
        using SectionMap =
            std::unordered_map<std::string,
                               std::variant<ConfigurationValueTypes...>>;

    public:
        Configuration() = default;
        ~Configuration() = default;

    private:
        std::unordered_map<std::string, SectionMap> m_sections;

    public:
        template <typename ValueType>
        void set(std::string_view sectionName,
                 std::string_view key,
                 ValueType&& value)
        {
            m_sections[std::string{sectionName}].insert(
                { std::string{key}, std::forward<ValueType>(value)});
        }

        template <typename ValueType>
        auto get(
            std::string_view sectionName,
            std::string_view key) const -> std::optional<std::reference_wrapper<const ValueType>>
        {
            const auto sectionIt = m_sections.find(std::string{sectionName});
            if (sectionIt == m_sections.end())
                return std::nullopt;

            auto& sectionMap = sectionIt->second;
            const auto it = sectionMap.find(std::string{key});
            if (it == sectionMap.end())
                return std::nullopt;

            const auto* value = std::get_if<ValueType>(&(it->second));
            if (!value)
                return std::nullopt;

            return std::cref(*value);
        }
    };
}