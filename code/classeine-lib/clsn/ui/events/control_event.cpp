#include "control_event.h"

#include "clsn/ui/control.h"

namespace clsn::ui::events
{
    control_event::control_event(control& ctrl)
    : m_control{ctrl}
    {
    }

    auto control_event::get_control() const -> const control&
    {
        return m_control;
    }

    auto control_event::get_control() -> control&
    {
        return m_control;
    }
}
