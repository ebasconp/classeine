#include <iostream>

#include "clsn/core/Panic.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/CheckBox.h"
#include "clsn/ui/HBoxContainer.h"
#include "clsn/ui/Label.h"
#include "clsn/ui/MainWindow.h"
#include "clsn/ui/RadioButton.h"
#include "clsn/ui/RadioButtonGroup.h"
#include "clsn/ui/ToggleButton.h"
#include "clsn/ui/VBoxContainer.h"
#include "clsn/ui/XYContainer.h"


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

//    MainWindow<VBoxContainer> mw;

//    auto b1 = mw().makeAndAdd<Button>();
//    b1->setText("Click me");
//
//    auto b2 = mw().makeAndAdd<Button>();
//    b2->setText("Click me again");
//
//    auto b3 = mw().makeAndAdd<Button>();
//    b3->setText("Click me three");
//
//    auto b4 = mw().makeAndAdd<Button>();
//    b4->setText("Click me");
//
//    auto hbc = mw().makeAndAdd<HBoxContainer>();
//    auto b5 = hbc->makeAndAdd<Button>();
//    auto b6 = hbc->makeAndAdd<Button>();
//
//    b5->setText("B5");
//    b6->setText("B6");
//
//    b5->addActionListener([](auto& e)
//                          {
//                              std::cout << "B5" << std::endl; }
//    );
//    b6->addActionListener([](auto& ) { std::cout << "B6" << std::endl; });
//
//    static int n = 0;
//
//    b1->addActionListener(
//        [&b4](auto& e)
//        {
//            b4->setText(
//                std::string{"Click me (" + std::to_string(++n) + ")"});
//        });
//
//    b2->addActionListener(
//        [&b4, &b1](auto& e)
//        {
//            b4->setText(
//                std::string{"Click me (" + std::to_string(--n) + ")"});
//
//            b1->setVisible(!b1->isVisible());
//        });
//
//    b3->addActionListener(
//        [&b4](auto& e)
//        {
//            n = 0;
//            b4->setText(
//                std::string{"Click me (0)"});
//        });
//
//    b3->setEnabled(false);
//
//    b4->addActionListener([&b4](auto& e)
//                          {
//                              auto color = b4->getForegroundColor();
//                              if (color == Colors::BLACK)
//                                  color = Colors::RED;
//                              else if (color == Colors::RED)
//                                  color = Colors::GREEN;
//                              else if (color == Colors::GREEN)
//                                  color = Colors::BLUE;
//                              else
//                                  color = Colors::BLACK;
//
//                              b4->setForegroundColor(color);
//                          });

    UIManager::getInstance().installTheme("light");

    MainWindow<VBoxContainer> mw;
    mw.setSize({1000, 400}); //ETOTODO

    auto c0 = mw().makeAndAdd<Button>();
    c0->setText("Button");

    auto c1 = mw().makeAndAdd<Label>();
    c1->setText("Label");

    auto c2 = mw().makeAndAdd<HBoxContainer>();

    auto b1 = c2->makeAndAdd<Button>();
    auto b2 = c2->makeAndAdd<VBoxContainer>();

    auto rb1 = b2->makeAndAdd<RadioButton>();
    rb1->setText("RadioButton 1");

    auto rb2 = b2->makeAndAdd<RadioButton>();
    rb2->setText("RadioButton 2");
    rb2->setEnabled(false);

    auto rb3 = b2->makeAndAdd<RadioButton>();
    rb3->setText("RadioButton 3");

    RadioButtonGroup group;
    group.add(rb1);
    group.add(rb2);
    group.add(rb3);

    auto b3 = c2->makeAndAdd<Button>();
    b3->setText("b3");

    auto b4 = c2->makeAndAdd<CheckBox>();
    b4->setText("CheckBox");
    b4->setEnabled(false);

    auto container = c2->makeAndAdd<VBoxContainer>();
    auto b6 = container->makeAndAdd<Button>();
    auto b7 = container->makeAndAdd<Button>();

    auto b5 = c2->makeAndAdd<Button>();

    auto container2 = c2->makeAndAdd<VBoxContainer>();
    auto b8 = container2->makeAndAdd<Button>();
    auto b9 = container2->makeAndAdd<ToggleButton>();
    b9->setText("ToggleButton");

    c0->addActionListener([&b3](auto& )
    {
        b3->setVisible(!b3->isVisible());
        std::cout << "B3 visible: " << b3->isVisible() << std::endl;
    });

    auto xy =  mw().makeAndAdd<XYContainer>();

    auto b1xy = xy->makeAndAdd<Button>(Point{10, 10});
    b1xy->setText("Theme");
    b1xy->setBackgroundColor(Colors::makeRed());
    b1xy->addActionListener([&b1xy](auto& )
    {
        auto& themeName = UIManager::getInstance().getCurrentThemeName();

        b1xy->setText(themeName);
        auto newThemeName = themeName == "dark" ? "light" : "dark";
        UIManager::getInstance().installTheme(newThemeName);
    });

    auto b2xy = xy->makeAndAdd<Button>(Point{200, 10});
    b2xy->setText("Button 2");

    mw.setVisible(true);

}

int main()
{
    clsn::ui::UIManager::init();

    test();

    clsn::ui::UIManager::finalize();

    clsn::core::Entity::dump();

    return 0;
}