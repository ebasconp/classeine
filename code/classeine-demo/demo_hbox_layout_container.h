#pragma once

#include "clsn/ui/hbox_layout_container.h"

#include "clsn/ui/forward.h"

namespace clsn::demo
{
    class demo_hbox_layout_container : public clsn::ui::hbox_layout_container
    {
        std::shared_ptr<clsn::ui::button> m_button;
        std::shared_ptr<clsn::ui::empty_control> m_control;
        std::shared_ptr<clsn::ui::label> m_label;

    public:
        demo_hbox_layout_container();
    };
}