#pragma once

#include "Console.h"

namespace clsn::core
{
    template <typename... Args>
    void Panic(int exitCode, std::string_view fmtspec, const Args&... args)
    {
        Console::print_stream(std::cerr, "Runtime error: ");
        Console::println_stream(std::cerr, fmtspec, args...);
        exit(exitCode);
    }

    template <typename... Args>
    void Panic(std::string_view fmtspec, const Args&... args)
    {
        Panic(-1, fmtspec, args...);
    }
}