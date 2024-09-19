// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/non_instantiable.h>
#include <clsn/core/strings.h>

#include <iostream>

namespace clsn::core
{
    class console final : public non_instantiable
    {
    public:
        template <typename... Args>
        static void print_stream(std::ostream& os, std::string_view fmtspec, const Args&... args)
        {
            strings::format_stream(os, fmtspec, args...);
        }

        template <typename... Args>
        static void println_stream(std::ostream& os, std::string_view fmtspec, const Args&... args)
        {
            strings::format_stream(os, fmtspec, args...);
            os << '\n';
        }

        template <typename... Args>
        static void print(std::string_view fmtspec, const Args&... args)
        {
            print_stream(std::cout, fmtspec, args...);
        }

        template <typename... Args>
        static void println(std::string_view fmtspec, const Args&... args)
        {
            println_stream(std::cout, fmtspec, args...);
        }

#ifdef _CLSN_DEBUG_
        template <typename... Args>
        static void debug(std::string_view fmtspec, const Args&... args)
        {
            print("DEBUG: ");
            print(fmtspec, args...);
            std::cout << std::endl;
        }
#else
        static inline void debug(std::string_view, ...)
        {
        }
#endif
    };
}