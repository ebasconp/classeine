#include "demo_control_container.h"

#include <clsn/ui/Button.h>
#include <clsn/ui/CheckBox.h>
#include <clsn/ui/EmptyControl.h>
#include <clsn/ui/Graphics.h>
#include <clsn/ui/HBoxLayoutContainer.h>
#include <clsn/ui/Label.h>
#include <clsn/ui/PaddingControl.h>
#include <clsn/ui/RadioButton.h>
#include <clsn/ui/RadioButtonGroup.h>
#include <clsn/ui/ToggleButton.h>

#include <clsn/ui/renderers/CustomizableRenderer.h>

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
        m_buttons = this->add(Control::make<ui::HBoxLayoutContainer>());

        auto b1 = m_buttons->add(Control::make<ui::Button>());
        b1->setCaption("Button");

        auto b2 = m_buttons->add(Control::make<ui::Button>());
        b2->setCaption("Disabled");
        b2->setEnabled(false);

        auto b3 = m_buttons->add(
            Control::make<ui::ToggleButton>());
        b3->setCaption("Toggle");

    }

    void demo_control_container::make_labels()
    {
        m_buttons = this->add(Control::make<ui::HBoxLayoutContainer>());

        auto label1 = m_buttons->add(Control::make<ui::Label>());
        label1->setCaption("Top left");
        label1->setHorizontalAlignment(draw::TextHorizontalAlignment::left);
        label1->setVerticalAlignment(draw::TextVerticalAlignment::top);
        label1->setBackgroundColor(draw::Color{255, 128, 0});

        auto label2 = m_buttons->add(Control::make<ui::Label>());
        label2->setCaption("Middle center");
        label2->setHorizontalAlignment(draw::TextHorizontalAlignment::center);
        label2->setVerticalAlignment(draw::TextVerticalAlignment::middle);
        label2->setBackgroundColor(draw::Color{230, 150, 0});


        auto label3 = m_buttons->add(Control::make<ui::Label>());
        label3->setCaption("Bottom right");
        label3->setHorizontalAlignment(draw::TextHorizontalAlignment::right);
        label3->setVerticalAlignment(draw::TextVerticalAlignment::bottom);
        label3->setBackgroundColor(draw::Color{200, 180, 0});
        label3->setEnabled(false);
    }

    void demo_control_container::make_radio_buttons()
    {
        m_radio_buttons = this->add(Control::make<ui::HBoxLayoutContainer>());

        auto enabled_ones = m_radio_buttons->add(Control::make<ui::VBoxLayoutContainer>());

        auto rb1 = enabled_ones->add(Control::make<ui::RadioButton>());
        rb1->setCaption("Option 1");

        auto rb2 = enabled_ones->add(Control::make<ui::RadioButton>());
        rb2->setCaption("Option 2");

        auto rb3 = enabled_ones->add(Control::make<ui::RadioButton>());
        rb3->setCaption("Option 3");

        m_radio_button_group.add(rb1);
        m_radio_button_group.add(rb2);
        m_radio_button_group.add(rb3);

        auto disabled_ones = m_radio_buttons->add(Control::make<ui::VBoxLayoutContainer>());

        auto db1 = disabled_ones->add(Control::make<ui::RadioButton>());
        db1->setCaption("One");
        db1->setChecked(true);
        db1->setEnabled(false);

        auto db2 = disabled_ones->add(Control::make<ui::RadioButton>());
        db2->setCaption("Two");
        db2->setEnabled(false);

        auto db3 = disabled_ones->add(Control::make<ui::RadioButton>());
        db3->setCaption("Three");
        db3->setEnabled(false);
    }


    void demo_control_container::make_check_boxes()
    {
        m_check_boxes = this->add(Control::make<ui::HBoxLayoutContainer>());

        auto padding = m_check_boxes->add(Control::make<ui::PaddingControl<ui::EmptyControl>>());
        padding->setForegroundColor(draw::Color{0, 240, 180});
        padding->setSize(8);

        auto& empty = padding->getInnerControl();
        empty.setRenderer(std::make_unique<ui::renderers::CustomizableRenderer>(
            [](ui::Graphics& gfx, const draw::Region& rgn, auto& )
            {
                gfx.setDrawColor(draw::Color{0, 80, 160});
                gfx.drawFillRectangle(rgn);

                gfx.setDrawColor(draw::Color{128, 150, 255});
                gfx.drawFillCircle(rgn + draw::Region{ 10, 10, -20, -20 });
            }
        ));


        auto enabled_ones = m_check_boxes->add(Control::make<ui::VBoxLayoutContainer>());

        auto rb1 = enabled_ones->add(Control::make<ui::CheckBox>());
        rb1->setCaption("Option 1");

        auto rb2 = enabled_ones->add(Control::make<ui::CheckBox>());
        rb2->setCaption("Option 2");

        auto rb3 = enabled_ones->add(Control::make<ui::CheckBox>());
        rb3->setCaption("Option 3");

        auto disabled_ones = m_check_boxes->add(Control::make<ui::VBoxLayoutContainer>());

        auto db1 = disabled_ones->add(Control::make<ui::CheckBox>());
        db1->setCaption("One");
        db1->setEnabled(false);

        auto db2 = disabled_ones->add(Control::make<ui::CheckBox>());
        db2->setCaption("Two");
        db2->setChecked(true);
        db2->setEnabled(false);

        auto db3 = disabled_ones->add(Control::make<ui::CheckBox>());
        db3->setCaption("Three");
        db3->setEnabled(false);

    }
}