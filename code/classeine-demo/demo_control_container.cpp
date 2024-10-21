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
        m_buttons = this->add(control::make<ui::hbox_layout_container>());

        auto b1 = m_buttons->add(control::make<ui::button>());
        b1->setCaption("Button");

        auto b2 = m_buttons->add(control::make<ui::button>());
        b2->setCaption("Disabled");
        b2->setEnabled(false);

        auto b3 = m_buttons->add(
            control::make<ui::toggle_button>());
        b3->setCaption("Toggle");

    }

    void demo_control_container::make_labels()
    {
        m_buttons = this->add(control::make<ui::hbox_layout_container>());

        auto label1 = m_buttons->add(control::make<ui::label>());
        label1->setCaption("Top left");
        label1->set_horizontal_alignment(draw::TextHorizontalAlignment::left);
        label1->set_vertical_alignment(draw::TextVerticalAlignment::top);
        label1->setBackgroundColor(draw::Color{255, 128, 0});

        auto label2 = m_buttons->add(control::make<ui::label>());
        label2->setCaption("Middle center");
        label2->set_horizontal_alignment(draw::TextHorizontalAlignment::center);
        label2->set_vertical_alignment(draw::TextVerticalAlignment::middle);
        label2->setBackgroundColor(draw::Color{230, 150, 0});


        auto label3 = m_buttons->add(control::make<ui::label>());
        label3->setCaption("Bottom right");
        label3->set_horizontal_alignment(draw::TextHorizontalAlignment::right);
        label3->set_vertical_alignment(draw::TextVerticalAlignment::bottom);
        label3->setBackgroundColor(draw::Color{200, 180, 0});
        label3->setEnabled(false);
    }

    void demo_control_container::make_radio_buttons()
    {
        m_radio_buttons = this->add(control::make<ui::hbox_layout_container>());

        auto enabled_ones = m_radio_buttons->add(control::make<ui::vbox_layout_container>());

        auto rb1 = enabled_ones->add(control::make<ui::radio_button>());
        rb1->setCaption("Option 1");

        auto rb2 = enabled_ones->add(control::make<ui::radio_button>());
        rb2->setCaption("Option 2");

        auto rb3 = enabled_ones->add(control::make<ui::radio_button>());
        rb3->setCaption("Option 3");

        m_radio_button_group.add(rb1);
        m_radio_button_group.add(rb2);
        m_radio_button_group.add(rb3);

        auto disabled_ones = m_radio_buttons->add(control::make<ui::vbox_layout_container>());

        auto db1 = disabled_ones->add(control::make<ui::radio_button>());
        db1->setCaption("One");
        db1->setChecked(true);
        db1->setEnabled(false);

        auto db2 = disabled_ones->add(control::make<ui::radio_button>());
        db2->setCaption("Two");
        db2->setEnabled(false);

        auto db3 = disabled_ones->add(control::make<ui::radio_button>());
        db3->setCaption("Three");
        db3->setEnabled(false);
    }


    void demo_control_container::make_check_boxes()
    {
        m_check_boxes = this->add(control::make<ui::hbox_layout_container>());

        auto padding = m_check_boxes->add(control::make<ui::padding_control<ui::empty_control>>());
        padding->setForegroundColor(draw::Color{0, 240, 180});
        padding->setSize(8);

        auto& empty = padding->get_inner_control();
        empty.set_renderer(std::make_unique<ui::renderers::customizable_renderer>(
            [](ui::graphics& gfx, const draw::Region& rgn, auto& )
            {
                gfx.set_draw_color(draw::Color{0, 80, 160});
                gfx.draw_fill_rectangle(rgn);

                gfx.set_draw_color(draw::Color{128, 150, 255});
                gfx.draw_fill_circle(rgn + draw::Region{ 10, 10, -20, -20 });
            }
        ));


        auto enabled_ones = m_check_boxes->add(control::make<ui::vbox_layout_container>());

        auto rb1 = enabled_ones->add(control::make<ui::check_box>());
        rb1->setCaption("Option 1");

        auto rb2 = enabled_ones->add(control::make<ui::check_box>());
        rb2->setCaption("Option 2");

        auto rb3 = enabled_ones->add(control::make<ui::check_box>());
        rb3->setCaption("Option 3");

        auto disabled_ones = m_check_boxes->add(control::make<ui::vbox_layout_container>());

        auto db1 = disabled_ones->add(control::make<ui::check_box>());
        db1->setCaption("One");
        db1->setEnabled(false);

        auto db2 = disabled_ones->add(control::make<ui::check_box>());
        db2->setCaption("Two");
        db2->setChecked(true);
        db2->setEnabled(false);

        auto db3 = disabled_ones->add(control::make<ui::check_box>());
        db3->setCaption("Three");
        db3->setEnabled(false);

    }
}