#include "demo_flow_layout_container.h"

#include <clsn/ui/button.h>

namespace clsn::demo
{
    demo_flow_layout_container::demo_flow_layout_container()
    {
        set_background_color(draw::color{128, 0, 192});

        m_file = (*this).make_and_add<ui::button>();
        m_file->set_text("File");

        m_edit = (*this).make_and_add<ui::button>();
        m_edit->set_text("Edit");

        m_view = (*this).make_and_add<ui::button>();
        m_view->set_text("View");

        m_tools = (*this).make_and_add<ui::button>();
        m_tools->set_text("Tools");

        m_window = (*this).make_and_add<ui::button>();
        m_window->set_text("Window");

        m_help = (*this).make_and_add<ui::button>();
        m_help->set_text("Help");
        m_help->set_background_color(draw::color{255, 128, 64});
    }
}