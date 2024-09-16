#pragma once

#include <clsn/ui/xy_layout_container.h>

#include <clsn/ui/forward.h>

namespace clsn::demo
{
    class demo_xy_layout_container : public ui::xy_layout_container
    {
    public:
        demo_xy_layout_container();

    private:
        std::shared_ptr<ui::button> m_button3;
    };
}