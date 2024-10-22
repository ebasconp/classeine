// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/core/strings.h>
#include <clsn/core/system.h>

#include <charconv>

namespace clsn::core
{
    auto strings::to_int(std::string_view value) -> std::optional<int>
    {
        int result;
        auto [ptr, ec] = std::from_chars(value.data(), value.data() + value.size(), result);
        if (ec == std::errc()) {
            return result;
        }

        return std::nullopt;
    }

    auto strings::to_string(int value) -> std::string
    {
        return std::to_string(value);
    }

    auto strings::to_string(double value) -> std::string
    {
        return std::to_string(value);
    }

    auto strings::to_string(bool value) -> std::string
    {
        return value ? "true" : "false";
    }

    auto strings::to_string(std::string_view value) -> std::string
    {
        return std::string{value};
    }

    auto strings::to_string(const std::string& value) -> const std::string&
    {
        return value;
    }

    auto strings::to_string(const char* value) -> std::string
    {
        return value;
    }

    void strings::populate_values_as_strings(std::vector<std::string>& )
    {
        // Do nothing
    }

    auto strings::format_stream(std::ostream& os, std::string_view spec) -> std::ostream&
    {
        os << spec;
        return os;
    }

    void strings::format_values(std::ostream& os, std::string_view fmtspec, const std::vector<std::string>& values)
    {
        auto count = fmtspec.length();

        auto non_counted_index = 0;

        for (auto i = 0U; i < count; i++)
        {
            char thisk = fmtspec[i];

            if (thisk != '{')
            {
                os << thisk;
                continue;
            }

            if (thisk == '{' && i < count - 1 && fmtspec[i + 1] == '{')
            {
                os << '{';
                i++;
                continue;
            }

            auto closing_idx = fmtspec.find('}', i + 1);
            if (closing_idx == std::string_view::npos)
                system::panic("} not found");

            auto sub = fmtspec.substr(i + 1, closing_idx - i - 1);

            auto arg_index = sub.empty() ? non_counted_index++ : to_int(sub);
            if (!arg_index.has_value())
                system::panic("Invalid format index");

            if (*arg_index >= static_cast<int>(values.size()))
                system::panic("Invalid index. Index higher than number of values");

            os << values[*arg_index];
            i = static_cast<int>(closing_idx);
        }
    }
}