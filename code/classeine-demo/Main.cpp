#include <iostream>

#include "clsn/core/Panic.h"

#include "clsn/draw/Colors.h"

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

    UIManager::getInstance().installTheme("light");

    MainWindow<VBoxContainer> mw;

    mw.setText("Welcome to Classeine");
    mw.setSize({1000, 600}); //ETOTODO

    auto flowc = mw().makeAndAdd<FlowContainer>();
    auto b0flowc = flowc->makeAndAdd<Button>();
    b0flowc->setText("File");

    auto b1flowc = flowc->makeAndAdd<Button>();
    b1flowc->setText("Edit");

    auto b2flowc = flowc->makeAndAdd<Button>();
    b2flowc->setText("View");

    auto b3flowc = flowc->makeAndAdd<Button>();
    b3flowc->setText("Window");

    auto b4flowc = flowc->makeAndAdd<Button>();
    b4flowc->setText("Help");

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

    auto dc = mw().makeAndAdd<DualContainer>();
    dc->setOrientation(DualContainerOrientation::horizontal);
    auto cb1 = dc->makeAndAdd<CheckBox>(DualContainerConstraint::use_all_available_space);
    cb1->setText("All available");
    auto tb1 = dc->makeAndAdd<Button>(DualContainerConstraint::use_preferred_size);
    tb1->setText("Preferred");

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