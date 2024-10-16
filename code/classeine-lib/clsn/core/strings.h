// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/non_instantiable.h>

#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace clsn::core
{
    class strings final : public non_instantiable
    {
    public:
        static auto to_int(std::string_view ) -> std::optional<int>;

        template <typename T>
        static auto to_string(const T& value) -> std::string
        {
            return value.to_string();
        }

        template <typename T>
        static auto to_string(const T* value) -> std::string
        {
            if (value == nullptr)
                return "[nullptr]";

            std::stringstream ss;
            ss << value;
            return ss.str();
        }

        static auto to_string(int value) -> std::string;
        static auto to_string(double value) -> std::string;
        static auto to_string(bool value) -> std::string;
        static auto to_string(std::string_view value) -> std::string;
        static auto to_string(const std::string& value) -> const std::string&;
        static auto to_string(const char* value) -> std::string;

        static void populate_values_as_strings(std::vector<std::string>& );

        template <typename Head>
        static void populate_values_as_strings(std::vector<std::string>& values, const Head& head)
        {
            values.push_back(to_string(head));
        }

        template <typename Head, typename... Tail>
        static void populate_values_as_strings(std::vector<std::string>& values, const Head& head, const Tail&... tail)
        {
            values.push_back(to_string(head));
            populate_values_as_strings(values, tail...);
        }

        template <typename... Args>
        static auto get_values_as_strings(const Args&... args) -> std::vector<std::string>
        {
            std::vector<std::string> values;
            populate_values_as_strings(values, args...);
            return values;
        }

        static void format_values(std::ostream& os, std::string_view fmtspec, const std::vector<std::string>& values);

        template <typename... Args>
        static auto format_stream(std::ostream& os, std::string_view fmtspec, const Args&... args) -> std::ostream&
        {
            auto values = get_values_as_strings(args...);
            format_values(os, fmtspec, values);
            return os;
        }

        // This overload is a helper to make printing interface consistent.
        // It does not perform any validation or parsing
        // on the spec parameter.
        static auto format_stream(std::ostream& os, std::string_view spec) -> std::ostream&;

        template <typename... Args>
        static auto format(std::string_view fmtspec, const Args&... args) -> std::string
        {
            std::stringstream ss;
            format_stream(ss, fmtspec, args...);
            return ss.str();
        }
    };
}