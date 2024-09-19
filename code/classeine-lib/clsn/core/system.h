// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/console.h>
#include <clsn/core/non_instantiable.h>

namespace clsn::core
{
    class system : public non_instantiable
    {
    public:
        template <typename... Args>
        static void panic(int exitCode, std::string_view fmtspec, const Args&... args)
        {
            console::print_stream(std::cerr, "RUNTIME ERROR: ");
            console::println_stream(std::cerr, fmtspec, args...);
            exit(exitCode);
        }

        template <typename... Args>
        static void panic(std::string_view fmtspec, const Args&... args)
        {
            panic(-1, fmtspec, args...);
        }
    };
}