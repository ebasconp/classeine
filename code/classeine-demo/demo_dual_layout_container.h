#pragma once

#include <clsn/ui/DualLayoutContainer.h>

#include <clsn/ui/Forward.h>

namespace clsn::demo
{
    class demo_dual_layout_container : public ui::DualLayoutContainer
    {
    public:
        demo_dual_layout_container();

    private:
        std::shared_ptr<ui::Button> m_button;
    };
}