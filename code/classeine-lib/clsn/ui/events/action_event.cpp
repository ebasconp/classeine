#include "action_event.h"

namespace clsn::ui::events
{
    action_event::action_event(control& ctrl, const std::string& action_name)
    : control_event{ctrl}
    , m_action_name{action_name}
    {
    }

    auto action_event::get_action_name() const -> const std::string&
    {
        return m_action_name;
    }
}
