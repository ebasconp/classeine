#include "demo_flow_layout_container.h"

#include <clsn/ui/button.h>

namespace clsn::demo
{
    demo_flow_layout_container::demo_flow_layout_container()
    {
        set_background_color(draw::color{128, 0, 192});

        m_file = this->add(control::make<ui::button>());
        m_file->set_caption("File");

        m_edit = this->add(control::make<ui::button>());
        m_edit->set_caption("Edit");

        m_view = this->add(control::make<ui::button>());
        m_view->set_caption("View");

        m_tools = this->add(control::make<ui::button>());
        m_tools->set_caption("Tools");

        m_window = this->add(control::make<ui::button>());
        m_window->set_caption("Window");

        m_help = this->add(control::make<ui::button>());
        m_help->set_caption("Help");
        m_help->set_background_color(draw::color{255, 128, 64});
    }
}