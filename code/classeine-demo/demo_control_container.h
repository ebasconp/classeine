#pragma once

#include <clsn/ui/toggle_control_group.h>
#include <clsn/ui/vbox_layout_container.h>

#include <clsn/ui/forward.h>

namespace clsn::demo
{
    class demo_control_container : public ui::vbox_layout_container
    {
    public:
        demo_control_container();

    private:
        std::shared_ptr<ui::hbox_layout_container> m_buttons;
        std::shared_ptr<ui::hbox_layout_container> m_labels;
        std::shared_ptr<ui::hbox_layout_container> m_radio_buttons;
        std::shared_ptr<ui::hbox_layout_container> m_check_boxes;

        ui::toggle_control_group m_toggle_control_group;

        void make_buttons();
        void make_labels();
        void make_radio_buttons();
        void make_check_boxes();
    };
}