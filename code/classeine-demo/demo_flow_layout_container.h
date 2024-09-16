#pragma once

#include <clsn/ui/flow_layout_container.h>

#include <clsn/ui/forward.h>

namespace clsn::demo
{
    class demo_flow_layout_container : public ui::flow_layout_container
    {
    public:
        demo_flow_layout_container();

    private:
        std::shared_ptr<ui::button> m_file;
        std::shared_ptr<ui::button> m_edit;
        std::shared_ptr<ui::button> m_view;
        std::shared_ptr<ui::button> m_tools;
        std::shared_ptr<ui::button> m_window;
        std::shared_ptr<ui::button> m_help;
    };
}