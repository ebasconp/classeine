#include "Panic.h"

#include <cstdlib>
#include <iostream>

namespace clsn::core
{
    void Panic(const std::string& msg, int errorCode)
    {
        std::cout << "Runtime error: " << msg << std::endl;
        exit(errorCode);
    }
}