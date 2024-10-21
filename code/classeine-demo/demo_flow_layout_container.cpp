#include "demo_flow_layout_container.h"

#include <clsn/ui/button.h>

namespace clsn::demo
{
    demo_flow_layout_container::demo_flow_layout_container()
    {
        setBackgroundColor(draw::color{128, 0, 192});

        m_file = this->add(control::make<ui::button>());
        m_file->setCaption("File");

        m_edit = this->add(control::make<ui::button>());
        m_edit->setCaption("Edit");

        m_view = this->add(control::make<ui::button>());
        m_view->setCaption("View");

        m_tools = this->add(control::make<ui::button>());
        m_tools->setCaption("Tools");

        m_window = this->add(control::make<ui::button>());
        m_window->setCaption("Window");

        m_help = this->add(control::make<ui::button>());
        m_help->setCaption("Help");
        m_help->setBackgroundColor(draw::color{255, 128, 64});
    }
}