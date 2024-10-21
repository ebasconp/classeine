// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/NonInstantiable.h>

#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace clsn::core
{
    class Strings final : public NonInstantiable
    {
    public:
        static auto toInt(std::string_view ) -> std::optional<int>;

        template <typename T>
        static auto toString(const T& value) -> std::string
        {
            return value.toString();
        }

        template <typename T>
        static auto toString(const T* value) -> std::string
        {
            if (value == nullptr)
                return "[nullptr]";

            std::stringstream ss;
            ss << value;
            return ss.str();
        }

        static auto toString(int value) -> std::string;
        static auto toString(double value) -> std::string;
        static auto toString(bool value) -> std::string;
        static auto toString(std::string_view value) -> std::string;
        static auto toString(const std::string& value) -> const std::string&;
        static auto toString(const char* value) -> std::string;

        static void populateValuesAsStrings(std::vector<std::string>& );

        template <typename Head>
        static void populateValuesAsStrings(std::vector<std::string>& values, const Head& head)
        {
            values.push_back(toString(head));
        }

        template <typename Head, typename... Tail>
        static void populateValuesAsStrings(std::vector<std::string>& values, const Head& head, const Tail&... tail)
        {
            values.push_back(toString(head));
            populateValuesAsStrings(values, tail...);
        }

        template <typename... Args>
        static auto get_values_as_strings(const Args&... args) -> std::vector<std::string>
        {
            std::vector<std::string> values;
            populateValuesAsStrings(values, args...);
            return values;
        }

        static void formatValues(std::ostream& os, std::string_view fmtspec, const std::vector<std::string>& values);

        template <typename... Args>
        static auto formatStream(std::ostream& os, std::string_view fmtspec, const Args&... args) -> std::ostream&
        {
            auto values = get_values_as_strings(args...);
            formatValues(os, fmtspec, values);
            return os;
        }

        // This overload is a helper to make printing interface consistent.
        // It does not perform any validation or parsing
        // on the spec parameter.
        static auto formatStream(std::ostream& os, std::string_view spec) -> std::ostream&;

        template <typename... Args>
        static auto format(std::string_view fmtspec, const Args&... args) -> std::string
        {
            std::stringstream ss;
            formatStream(ss, fmtspec, args...);
            return ss.str();
        }
    };
}