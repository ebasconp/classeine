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
    class configuration final
    {
        using section_map =
            std::unordered_map<std::string,
                               std::variant<ConfigurationValueTypes...>>;

    public:
        configuration() = default;
        ~configuration() = default;

    private:
        std::unordered_map<std::string, section_map> m_sections;

    public:
        template <typename ValueType>
        void set(std::string_view section_name,
                 std::string_view key,
                 ValueType&& value)
        {
            m_sections[std::string{section_name}].insert(
                { std::string{key}, std::forward<ValueType>(value)});
        }

        template <typename ValueType>
        auto get(
            std::string_view section_name,
            std::string_view key) const -> std::optional<std::reference_wrapper<const ValueType>>
        {
            const auto section_it = m_sections.find(std::string{section_name});
            if (section_it == m_sections.end())
                return std::nullopt;

            auto& section_map = section_it->second;
            const auto it = section_map.find(std::string{key});
            if (it == section_map.end())
                return std::nullopt;

            const auto* value = std::get_if<ValueType>(&(it->second));
            if (!value)
                return std::nullopt;

            return std::cref(*value);
        }
    };
}