#include <iostream>
#include <string>

#include "classeine/core/StringUtils.h"


int main()
{
    auto s = classeine::core::StringUtils::buildString("Hello", " ", "world ", 2023);

    std::cout << s << std::endl;

    return 0;
}