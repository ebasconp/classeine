#pragma once

#include <string>

namespace clsn::core
{
    void Panic(const std::string& msg, int errorCode = -1);
}