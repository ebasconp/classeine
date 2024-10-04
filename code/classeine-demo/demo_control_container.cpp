#include "demo_control_container.h"

#include <clsn/ui/button.h>
#include <clsn/ui/check_box.h>
#include <clsn/ui/empty_control.h>
#include <clsn/ui/graphics.h>
#include <clsn/ui/hbox_layout_container.h>
#include <clsn/ui/label.h>
#include <clsn/ui/padding_control.h>
#include <clsn/ui/radio_button.h>
#include <clsn/ui/radio_button_group.h>
#include <clsn/ui/toggle_button.h>

#include <clsn/ui/renderers/customizable_renderer.h>

namespace clsn::demo
{
    demo_control_container::demo_control_container()
    {
        make_buttons();
        make_labels();
        make_radio_buttons();
        make_check_boxes();
    }


    void demo_control_container::make_buttons()
    {
        m_buttons = (*this).make_and_add<ui::hbox_layout_container>();

        auto b1 = m_buttons->make_and_add<ui::button>();
        b1->set_caption("Button");

        auto b2 = m_buttons->make_and_add<ui::button>();
        b2->set_caption("Disabled");
        b2->set_enabled(false);

        auto b3 = m_buttons->make_and_add<ui::toggle_button>();
        b3->set_caption("Toggle");

    }

    void demo_control_container::make_labels()
    {
        m_buttons = (*this).make_and_add<ui::hbox_layout_container>();

        auto label1 = m_buttons->make_and_add<ui::label>();
        label1->set_caption("Top left");
        label1->set_horizontal_alignment(draw::text_horizontal_alignment::left);
        label1->set_vertical_alignment(draw::text_vertical_alignment::top);
        label1->set_background_color(draw::color{255, 128, 0});

        auto label2 = m_buttons->make_and_add<ui::label>();
        label2->set_caption("Middle center");
        label2->set_horizontal_alignment(draw::text_horizontal_alignment::center);
        label2->set_vertical_alignment(draw::text_vertical_alignment::middle);
        label2->set_background_color(draw::color{230, 150, 0});


        auto label3 = m_buttons->make_and_add<ui::label>();
        label3->set_caption("Bottom right");
        label3->set_horizontal_alignment(draw::text_horizontal_alignment::right);
        label3->set_vertical_alignment(draw::text_vertical_alignment::bottom);
        label3->set_background_color(draw::color{200, 180, 0});
        label3->set_enabled(false);
    }

    void demo_control_container::make_radio_buttons()
    {
        m_radio_buttons = (*this).make_and_add<ui::hbox_layout_container>();

        auto enabled_ones = m_radio_buttons->make_and_add<ui::vbox_layout_container>();

        auto rb1 = enabled_ones->make_and_add<ui::radio_button>();
        rb1->set_caption("Option 1");

        auto rb2 = enabled_ones->make_and_add<ui::radio_button>();
        rb2->set_caption("Option 2");

        auto rb3 = enabled_ones->make_and_add<ui::radio_button>();
        rb3->set_caption("Option 3");

        m_radio_button_group.add(rb1);
        m_radio_button_group.add(rb2);
        m_radio_button_group.add(rb3);

        auto disabled_ones = m_radio_buttons->make_and_add<ui::vbox_layout_container>();

        auto db1 = disabled_ones->make_and_add<ui::radio_button>();
        db1->set_caption("One");
        db1->set_checked(true);
        db1->set_enabled(false);

        auto db2 = disabled_ones->make_and_add<ui::radio_button>();
        db2->set_caption("Two");
        db2->set_enabled(false);

        auto db3 = disabled_ones->make_and_add<ui::radio_button>();
        db3->set_caption("Three");
        db3->set_enabled(false);
    }


    void demo_control_container::make_check_boxes()
    {
        m_check_boxes = (*this).make_and_add<ui::hbox_layout_container>();

        auto padding = m_check_boxes->make_and_add<ui::padding_control<ui::empty_control>>();
        padding->set_foreground_color(draw::color{0, 240, 180});
        padding->set_size(8);

        auto& empty = padding->get_inner_control();
        empty.set_renderer(std::make_unique<ui::renderers::customizable_renderer>(
            [](ui::graphics& gfx, const draw::region& rgn, auto& )
            {
                gfx.set_draw_color(draw::color{0, 80, 160});
                gfx.draw_fill_rectangle(rgn);

                gfx.set_draw_color(draw::color{128, 150, 255});
                gfx.draw_fill_circle(rgn + draw::region{ 10, 10, -20, -20 });
            }
        ));


        auto enabled_ones = m_check_boxes->make_and_add<ui::vbox_layout_container>();

        auto rb1 = enabled_ones->make_and_add<ui::check_box>();
        rb1->set_caption("Option 1");

        auto rb2 = enabled_ones->make_and_add<ui::check_box>();
        rb2->set_caption("Option 2");

        auto rb3 = enabled_ones->make_and_add<ui::check_box>();
        rb3->set_caption("Option 3");

        auto disabled_ones = m_check_boxes->make_and_add<ui::vbox_layout_container>();

        auto db1 = disabled_ones->make_and_add<ui::check_box>();
        db1->set_caption("One");
        db1->set_enabled(false);

        auto db2 = disabled_ones->make_and_add<ui::check_box>();
        db2->set_caption("Two");
        db2->set_checked(true);
        db2->set_enabled(false);

        auto db3 = disabled_ones->make_and_add<ui::check_box>();
        db3->set_caption("Three");
        db3->set_enabled(false);

    }
}