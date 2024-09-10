#include "mouse_click_event.h"

namespace clsn::ui::events
{
    mouse_click_event::mouse_click_event(mouse_click_status status, const point& point)
    : m_status{status}
    , m_point{point}
    {
    }

    auto mouse_click_event::get_status() const noexcept -> mouse_click_status
    {
        return m_status;
    }

    auto mouse_click_event::get_point() const noexcept -> const point&
    {
        return m_point;
    }
}