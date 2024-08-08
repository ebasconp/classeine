#include <iostream>

#include "clsn/core/console.h"
#include "clsn/core/system.h"

#include "clsn/draw/colors.h"

#include "clsn/ui/Button.h"
#include "clsn/ui/CheckBox.h"
#include "clsn/ui/DualContainer.h"
#include "clsn/ui/FlowContainer.h"
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

    class A
    {
    public:
        std::string to_string() const { return "A.to_string()"; }
    };

    std::string s = "Juan";
    int n = 10;

    std::string f1 = "Hello, my  name is {0} and I am {1} years old";
    std::string f2 = "Hola, tengo {1} años y me llamo {0}";
    std::string f3 = "Hallo, mein Name ist {} und Ich bin {} Jahre alte";

    console::println(f1, s, n);
    console::println(f2, s, n);
    console::debug(f3, s, n);
    console::println("Hello world");

    UIManager::getInstance().installTheme("light");

    MainWindow<VBoxContainer> mw;

    mw.set_text("Welcome to Classeine");
    mw.set_size({1000, 600}); //ETOTODO

    auto flowc = mw().makeAndAdd<FlowContainer>();
    auto b0flowc = flowc->makeAndAdd<Button>();
    b0flowc->set_text("File");

    auto b1flowc = flowc->makeAndAdd<Button>();
    b1flowc->set_text("Edit");

    auto b2flowc = flowc->makeAndAdd<Button>();
    b2flowc->set_text("View");

    auto b3flowc = flowc->makeAndAdd<Button>();
    b3flowc->set_text("Window");

    auto b4flowc = flowc->makeAndAdd<Button>();
    b4flowc->set_text("Help");

    auto c0 = mw().makeAndAdd<Button>();
    c0->set_text("Button");

    auto c1 = mw().makeAndAdd<Label>();
    c1->set_text("Label");

    auto c2 = mw().makeAndAdd<HBoxContainer>();

    auto b1 = c2->makeAndAdd<Button>();
    auto b2 = c2->makeAndAdd<VBoxContainer>();

    auto rb1 = b2->makeAndAdd<RadioButton>();
    rb1->set_text("RadioButton 1");

    auto rb2 = b2->makeAndAdd<RadioButton>();
    rb2->set_text("RadioButton 2");
    rb2->set_enabled(false);

    auto rb3 = b2->makeAndAdd<RadioButton>();
    rb3->set_text("RadioButton 3");

    RadioButtonGroup group;
    group.add(rb1);
    group.add(rb2);
    group.add(rb3);

    auto b3 = c2->makeAndAdd<Button>();
    b3->set_text("b3");

    auto b4 = c2->makeAndAdd<CheckBox>();
    b4->set_text("CheckBox");
    b4->set_enabled(false);

    auto container = c2->makeAndAdd<VBoxContainer>();
    auto b6 = container->makeAndAdd<Button>();
    auto b7 = container->makeAndAdd<Button>();

    auto b5 = c2->makeAndAdd<Button>();

    auto container2 = c2->makeAndAdd<VBoxContainer>();
    auto b8 = container2->makeAndAdd<Button>();
    auto b9 = container2->makeAndAdd<ToggleButton>();
    b9->set_text("ToggleButton");

    c0->add_action_listener([&b3](auto& )
    {
        b3->set_visible(!b3->is_visible());
        std::cout << "B3 visible: " << b3->is_visible() << std::endl;
    });

    auto xy =  mw().makeAndAdd<XYContainer>();

    auto b1xy = xy->makeAndAdd<Button>(point{10, 10});
    b1xy->set_text("Theme");
    b1xy->set_background_color(colors::make_red());
    b1xy->add_action_listener([&b1xy](auto& )
    {
        auto& themeName = UIManager::getInstance().getCurrentThemeName();

        b1xy->set_text(themeName);
        auto newThemeName = themeName == "dark" ? "light" : "dark";
        UIManager::getInstance().installTheme(newThemeName);
    });

    auto b2xy = xy->makeAndAdd<Button>(point{200, 10});
    b2xy->set_text("Button 2");

    auto dc = mw().makeAndAdd<DualContainer>();
    dc->setOrientation(DualContainerOrientation::horizontal);
    auto cb1 = dc->makeAndAdd<CheckBox>(DualContainerConstraint::use_all_available_space);
    cb1->set_text("All available");
    auto tb1 = dc->makeAndAdd<Button>(DualContainerConstraint::use_preferred_size);
    tb1->set_text("Preferred");

    mw.set_visible(true);

}

int main()
{
    clsn::ui::UIManager::init();

    test();

    clsn::ui::UIManager::finalize();

    clsn::core::entity::dump();

    return 0;
}