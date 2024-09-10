#include "control_resized_event.h"

namespace clsn::ui::events
{

control_resized_event::control_resized_event(
    control& ctrl, int width, int height)
: control_event{ctrl}
, m_width{width}
, m_height{height}
{
}

auto control_resized_event::get_width() const noexcept -> int { return m_width; }
auto control_resized_event::get_height() const noexcept -> int { return m_height; }

}