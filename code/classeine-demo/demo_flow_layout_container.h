#pragma once

#include <clsn/ui/FlowLayoutContainer.h>

#include <clsn/ui/Forward.h>

namespace clsn::demo
{
    class demo_flow_layout_container : public ui::FlowLayoutContainer
    {
    public:
        demo_flow_layout_container();

    private:
        std::shared_ptr<ui::Button> m_file;
        std::shared_ptr<ui::Button> m_edit;
        std::shared_ptr<ui::Button> m_view;
        std::shared_ptr<ui::Button> m_tools;
        std::shared_ptr<ui::Button> m_window;
        std::shared_ptr<ui::Button> m_help;
    };
}