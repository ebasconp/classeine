#include "control_resized_event.h"

namespace clsn::ui::events
{

control_resized_event::control_resized_event(int width, int height)
: m_width{width}
, m_height{height}
{
}

auto control_resized_event::get_width() const noexcept -> int { return m_width; }
auto control_resized_event::get_height() const noexcept -> int { return m_height; }

}