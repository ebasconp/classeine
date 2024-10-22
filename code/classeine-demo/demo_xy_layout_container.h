#pragma once

#include <clsn/ui/XYLayoutContainer.h>

#include <clsn/ui/Forward.h>

namespace clsn::demo
{
    class demo_xy_layout_container : public ui::XYLayoutContainer
    {
    public:
        demo_xy_layout_container();

    private:
        std::shared_ptr<ui::Button> m_button3;
    };
}