#include <iostream>
#include <string>

#include "clsn/core/StringUtils.h"

#include "clsn/ui/MainWindow.h"

class Person
{
    CLSN_PROPERTY(std::string, FirstName);
    CLSN_PROPERTY(std::string, LastName);
    CLSN_PROPERTY(int, Age);
};

int main()
{
    Person p;
    p.setFirstName("Juan");
    p.setLastName("Perez");
    p.setAge(15);

    auto listener = [](auto& prop, auto& old, auto& now)
    {
        std::cout << "(" << prop << ") " << old << " ==> " << now << "\n";
    };

    p.addFirstNameChangedListener(listener);
    p.addLastNameChangedListener(listener);
    p.addAgeChangedListener(listener);

    std::cout << p.getLastName() << ", " << p.getFirstName() << " AGE: " << p.getAge() << "\n";

    p.setFirstName("Ariel");
    p.setLastName("Lopez");
    p.setAge(25);

    clsn::core::StringUtils::buildStream(std::cout, "Hello", " Classeine ", "world ", 2023, "\n");

    clsn::ui::MainWindow<int> mw;
    mw.setTitle("Hello Claseine World");

    std::cout << mw.getTitle() << std::endl;

    mw.addTitleValueChangedEventListener([](auto& propertyName, auto& oldValue, auto& newValue)
    {
        clsn::core::StringUtils::buildStream(std::cout, propertyName, " changed from [", oldValue, "] to [", newValue, "]\n");
    });

    mw.setTitle("Hello my friends");


    clsn::core::StringUtils::buildStream(std::cout, "Bye Classeine world\n");
    return 0;
}
