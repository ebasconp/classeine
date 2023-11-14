#include <iostream>
#include <string>

#include "clsn/core/StringUtils.h"

#include "clsn/ui/MainWindow.h"


int main()
{
    clsn::core::StringUtils::buildStream(std::cout, "Hello", " Classeine ", "world ", 2023, "\n");

    clsn::ui::MainWindow<int> mw;
    mw.setTitle("Hello Claseine World");

    std::cout << mw.getTitle() << std::endl;

    mw.addTitleValueChangedEventListener([](auto& oldValue, auto& newValue)
    {
        clsn::core::StringUtils::buildStream(std::cout, "Title changed from [", oldValue, "] to [", newValue, "]\n");
    });

    mw.setTitle("Hello my friends");

    clsn::core::StringUtils::buildStream(std::cout, "Bye Classeine world\n");
    return 0;
}
