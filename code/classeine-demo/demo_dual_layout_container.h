#pragma once

#include <clsn/ui/dual_layout_container.h>

#include <clsn/ui/forward.h>

namespace clsn::demo
{
    class demo_dual_layout_container : public ui::dual_layout_container
    {
    public:
        demo_dual_layout_container();

    private:
        std::shared_ptr<ui::button> m_button;
    };
}