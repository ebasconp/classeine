#include "mouse_moved_event.h"

namespace clsn::ui::events
{
    mouse_moved_event::mouse_moved_event(const point& position)
    : m_position(position)
    {
    }

    auto mouse_moved_event::get_position() const noexcept -> const point&
    {
        return m_position;
    }
}