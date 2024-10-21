// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/core/Console.h>
#include <clsn/core/NonInstantiable.h>

namespace clsn::core
{
    class System : public NonInstantiable
    {
    public:
        template <typename... Args>
        static void panic(int exitCode, std::string_view fmtspec, const Args&... args)
        {
            Console::printStream(std::cerr, "RUNTIME ERROR: ");
            Console::printlnStream(std::cerr, fmtspec, args...);
            exit(exitCode);
        }

        template <typename... Args>
        static void panic(std::string_view fmtspec, const Args&... args)
        {
            panic(-1, fmtspec, args...);
        }
    };
}