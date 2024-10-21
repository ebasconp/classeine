// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/core/Strings.h>
#include "clsn/core/System.h"

#include <charconv>

namespace clsn::core
{
    auto Strings::toInt(std::string_view value) -> std::optional<int>
    {
        int result;
        auto [ptr, ec] = std::from_chars(value.data(), value.data() + value.size(), result);
        if (ec == std::errc()) {
            return result;
        }

        return std::nullopt;
    }

    auto Strings::toString(int value) -> std::string
    {
        return std::to_string(value);
    }

    auto Strings::toString(double value) -> std::string
    {
        return std::to_string(value);
    }

    auto Strings::toString(bool value) -> std::string
    {
        return value ? "true" : "false";
    }

    auto Strings::toString(std::string_view value) -> std::string
    {
        return std::string{value};
    }

    auto Strings::toString(const std::string& value) -> const std::string&
    {
        return value;
    }

    auto Strings::toString(const char* value) -> std::string
    {
        return value;
    }

    void Strings::populateValuesAsStrings(std::vector<std::string>& )
    {
        // Do nothing
    }

    auto Strings::formatStream(std::ostream& os, std::string_view spec) -> std::ostream&
    {
        os << spec;
        return os;
    }

    void Strings::formatValues(std::ostream& os, std::string_view fmtspec, const std::vector<std::string>& values)
    {
        auto count = fmtspec.length();

        auto nonCountedIndex = 0;

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

            auto closingIdx = fmtspec.find('}', i + 1);
            if (closingIdx == std::string_view::npos)
                System::panic("} not found");

            auto sub = fmtspec.substr(i + 1, closingIdx - i - 1);

            auto argIdx = sub.empty() ? nonCountedIndex++ : toInt(sub);
            if (!argIdx.has_value())
                System::panic("Invalid format index");

            if (*argIdx >= static_cast<int>(values.size()))
                System::panic("Invalid index. Index higher than number of values");

            os << values[*argIdx];
            i = static_cast<int>(closingIdx);
        }
    }
}