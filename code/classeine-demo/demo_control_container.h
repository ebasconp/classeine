#pragma once

#include <clsn/ui/RadioButtonGroup.h>
#include <clsn/ui/VBoxLayoutContainer.h>

#include <clsn/ui/Forward.h>

namespace clsn::demo
{
    class demo_control_container : public ui::VBoxLayoutContainer
    {
    public:
        demo_control_container();

    private:
        std::shared_ptr<ui::HBoxLayoutContainer> m_buttons;
        std::shared_ptr<ui::HBoxLayoutContainer> m_labels;
        std::shared_ptr<ui::HBoxLayoutContainer> m_radio_buttons;
        std::shared_ptr<ui::HBoxLayoutContainer> m_check_boxes;

        ui::RadioButtonGroup m_radio_button_group;

        void make_buttons();
        void make_labels();
        void make_radio_buttons();
        void make_check_boxes();
    };
}