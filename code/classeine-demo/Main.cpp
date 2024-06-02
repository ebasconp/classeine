#include <iostream>

#include "clsn/core/Panic.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/HBoxContainer.h"
#include "clsn/ui/MainWindow.h"
#include "clsn/ui/VBoxContainer.h"
//
//#include "clsn/core/EventListenerList.h"
//#include "clsn/core/Property.h"
//#include "clsn/core/ValueChangedEvent.h"

#include "clsn/ui/renderers/NullRenderer.h"

#include <memory>

void test()
{
    using namespace clsn::core;
    using namespace clsn::ui;
    using namespace clsn::ui::renderers;

    //    MainWindow<Button> mw;
    //    mw().setText("Hello world");
    //
    //    mw().addActionListener([&mw](auto& )
    //    {
    //        static int n = 0;
    //        mw().setText("Clicked " + std::to_string(++n) + " times");
    //    });

    MainWindow<VBoxContainer> mw;

    auto b1 = mw().makeAndAdd<Button>();
    b1->setText("Click me");

    auto b2 = mw().makeAndAdd<Button>();
    b2->setText("Click me again");

    auto b3 = mw().makeAndAdd<Button>();
    b3->setText("Click me three");

    auto b4 = mw().makeAndAdd<Button>();
    b4->setText("Click me");

    auto hbc = mw().makeAndAdd<HBoxContainer>();
    auto b5 = hbc->makeAndAdd<Button>();
    auto b6 = hbc->makeAndAdd<Button>();

    b5->setText("B5");
    b6->setText("B6");

    b5->addActionListener([](auto& e)
                          {
                              std::cout << "B5" << std::endl; }
    );
    b6->addActionListener([](auto& ) { std::cout << "B6" << std::endl; });

    static int n = 0;

    b1->addActionListener(
        [&b4](auto& e)
        {
            b4->setText(
                std::string{"Click me (" + std::to_string(++n) + ")"});
        });

    b2->addActionListener(
        [&b4, &b1](auto& e)
        {
            b4->setText(
                std::string{"Click me (" + std::to_string(--n) + ")"});

            b1->setVisible(!b1->isVisible());
        });

    b3->addActionListener(
        [&b4](auto& e)
        {
            n = 0;
            b4->setText(
                std::string{"Click me (0)"});
        });

    b3->setEnabled(false);

    b4->addActionListener([&b4](auto& e)
                          {
                              auto color = b4->getForegroundColor();
                              if (color == Colors::BLACK)
                                  color = Colors::RED;
                              else if (color == Colors::RED)
                                  color = Colors::GREEN;
                              else if (color == Colors::GREEN)
                                  color = Colors::BLUE;
                              else
                                  color = Colors::BLACK;

                              b4->setForegroundColor(color);
                          });

    mw.setVisible(true);
}

int main()
{
    test();

    clsn::core::Entity::dump();

    return 0;
}