#include <iostream>

#include "clsn/core/console.h"
#include "clsn/core/system.h"

#include "clsn/draw/colors.h"

#include "clsn/ui/button.h"
#include "clsn/ui/check_box.h"
#include "clsn/ui/dual_layout_container.h"
#include "clsn/ui/flow_layout_container.h"
#include "clsn/ui/hbox_layout_container.h"
#include "clsn/ui/label.h"
#include "clsn/ui/main_window.h"
#include "clsn/ui/padding_control.h"
#include "clsn/ui/radio_button.h"
#include "clsn/ui/radio_button_group.h"
#include "clsn/ui/toggle_button.h"
#include "clsn/ui/vbox_layout_container.h"
#include "clsn/ui/xy_layout_container.h"

#include "clsn/ui/renderers/customizable_renderer.h"
#include "clsn/ui/renderers/null_renderer.h"

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
    console::debug("{}", A{});

    ui_manager::get_instance().install_theme("light");

    main_window<vbox_layout_container> mw;

    mw.set_text("Welcome to Classeine");
    mw.set_size({1000, 600}); //ETOTODO

    auto flowc = mw().make_and_add<flow_layout_container>();
    auto b0flowc = flowc->make_and_add<button>();
    b0flowc->set_text("File");

    auto b1flowc = flowc->make_and_add<button>();
    b1flowc->set_text("Edit");

    auto b2flowc = flowc->make_and_add<button>();
    b2flowc->set_text("View");

    auto b3flowc = flowc->make_and_add<button>();
    b3flowc->set_text("window");

    auto b4flowc = flowc->make_and_add<button>();
    b4flowc->set_text("Help");

    auto c0 = mw().make_and_add<button>();
    c0->set_text("button");

    auto c1 = mw().make_and_add<label>();
    c1->set_text("label");

    auto c2 = mw().make_and_add<hbox_layout_container>();

    auto b1 = c2->make_and_add<button>();

    auto custom_renderer = std::make_unique<renderers::customizable_renderer>(
        [](clsn::ui::graphics& gfx, auto& rgn, auto& )
        {
            gfx.set_draw_color(clsn::draw::colors::make_purple());
            gfx.draw_fill_rectangle(rgn);
        });

    b1->set_renderer(std::move(custom_renderer));

    auto b2 = c2->make_and_add<vbox_layout_container>();

    auto rb1 = b2->make_and_add<radio_button>();
    rb1->set_text("radio_button 1");

    auto rb2 = b2->make_and_add<radio_button>();
    rb2->set_text("radio_button 2");
    rb2->set_enabled(false);

    auto rb3 = b2->make_and_add<radio_button>();
    rb3->set_text("radio_button 3");

    radio_button_group group;
    group.add(rb1);
    group.add(rb2);
    group.add(rb3);

    auto b3 = c2->make_and_add<padding_control<button>>();
    b3->get_inner_control().set_text("b3");
    b3->set_foreground_color(colors::make_cyan());
    b3->get_inner_control().add_action_listener([&b3](auto&)
    {
        auto new_size = (b3->get_size() + 1) % 16;
        b3->set_size(new_size);
    });

    auto b4 = c2->make_and_add<check_box>();
    b4->set_text("check_box");
    b4->set_enabled(false);

    auto container = c2->make_and_add<vbox_layout_container>();
    auto b6 = container->make_and_add<button>();
    auto b7 = container->make_and_add<button>();

    auto b5 = c2->make_and_add<button>();

    auto container2 = c2->make_and_add<vbox_layout_container>();
    auto b8 = container2->make_and_add<button>();
    auto b9 = container2->make_and_add<toggle_button>();
    b9->set_text("toggle_button");

    c0->add_action_listener([&b3](auto& )
    {
        b3->set_visible(!b3->is_visible());
        std::cout << "B3 visible: " << b3->is_visible() << std::endl;
    });

    auto xy =  mw().make_and_add<xy_layout_container>();

    auto b1xy = xy->make_and_add<button>(point{10, 10});
    b1xy->set_text("Theme");
    b1xy->set_background_color(colors::make_red());
    b1xy->add_action_listener([&b1xy](auto& )
    {
        auto& themeName = ui_manager::get_instance().get_current_theme_name();

        b1xy->set_text(themeName);
        auto newThemeName = themeName == "dark" ? "light" : "dark";
        ui_manager::get_instance().install_theme(newThemeName);
    });

    auto b2xy = xy->make_and_add<button>(point{200, 10});
    b2xy->set_text("button 2");

    auto dc = mw().make_and_add<dual_layout_container>();
    dc->set_orientation(dual_layout_orientation::horizontal);
    auto cb1 = dc->make_and_add<check_box>(dual_layout_constraint::use_all_available_space);
    cb1->set_text("All available");
    auto tb1 = dc->make_and_add<button>(dual_layout_constraint::use_preferred_size);
    tb1->set_text("Preferred");

    mw.set_visible(true);

}

int main()
{
    clsn::ui::ui_manager::init();

    test();

    clsn::ui::ui_manager::finalize();

    clsn::core::entity::dump();

    return 0;
}