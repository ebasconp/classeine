#include "demo_flow_layout_container.h"

#include <clsn/ui/Button.h>

namespace clsn::demo
{
    demo_flow_layout_container::demo_flow_layout_container()
    {
        setBackgroundColor(draw::Color{128, 0, 192});

        m_file = this->add(Control::make<ui::Button>());
        m_file->setCaption("File");

        m_edit = this->add(Control::make<ui::Button>());
        m_edit->setCaption("Edit");

        m_view = this->add(Control::make<ui::Button>());
        m_view->setCaption("View");

        m_tools = this->add(Control::make<ui::Button>());
        m_tools->setCaption("Tools");

        m_window = this->add(Control::make<ui::Button>());
        m_window->setCaption("Window");

        m_help = this->add(Control::make<ui::Button>());
        m_help->setCaption("Help");
        m_help->setBackgroundColor(draw::Color{255, 128, 64});
    }
}