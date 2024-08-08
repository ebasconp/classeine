#pragma once

#include "clsn/core/event.h"

#include "clsn/draw/point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    enum class mouse_click_status
    {
        released,
        pressed
    };

    class mouse_click_data
    {
    private:
        mouse_click_status m_status;
        point m_point;

    public:
        mouse_click_data(mouse_click_status status, const point& point)
        : m_status{status}
        , m_point{point}
        {
        }

        [[nodiscard]] auto getStatus() const noexcept -> mouse_click_status
        {
            return m_status;
        }

        [[nodiscard]] auto getPoint() const noexcept -> const point&
        {
            return m_point;
        }
    };

    using mouse_click_event = clsn::core::event<mouse_click_data>;
}