#include <iostream>

#include "clsn/core/Panic.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/MainWindow.h"

#include "clsn/core/EventListenerList.h"
#include "clsn/core/Property.h"
#include "clsn/core/ValueChangedEvent.h"

class Person
{
    CLSN_PROPERTY(std::string, true, FirstName);
    CLSN_PROPERTY(std::string, true, LastName);
    CLSN_PROPERTY(int, true, Id);
};

int main()
{
    Person p;
    p.setFirstName("Juan");
    p.setLastName("Perez");
    p.setId(123123);

    p.addLastNameChangedListener(
        [](auto& e)
        {
            std::cout << "LastName changed from: " << e.getOldValue() << " to "
                      << e.getNewValue() << std::endl;
        });

    p.setLastName("Lopez");

    std::cout << p.getLastName() << std::endl;

    using namespace clsn::core;
    using namespace clsn::ui;

    MainWindow<Button> mw;
    mw.setSize(Dimension{400, 300});

    mw.getControl().getEventManager().addActionListener([](auto& )
    {
        std::cout << "CLICK" <<  std::endl;
    });


    //
    //    auto textArea= mw.makeAndAdd<TextArea>(BorderLayoutConsts::CENTER);
    //
    //    auto button = mw.makeAndAdd<Button>(BorderLayoutConsts::NORTH);
    //    button->setText("Click me");
    //    button->addActionListener([&](auto& )
    //    {
    //        static int n = 0;
    //        textArea->setText(textArea.getText() + "\n" + (++n) + " clicks" );
    //    });
    //

    mw.setVisible(true);

    return 0;
}