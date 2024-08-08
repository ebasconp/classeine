#pragma once

#include "clsn/core/event.h"

#include "clsn/draw/point.h"

namespace clsn::ui::events
{
    using namespace clsn::draw;

    enum class MouseClickStatus
    {
        released,
        pressed
    };

    class MouseClickData
    {
    private:
        MouseClickStatus m_status;
        point m_point;

    public:
        MouseClickData(MouseClickStatus status, const point& point)
        : m_status{status}
        , m_point{point}
        {
        }

        [[nodiscard]] auto getStatus() const noexcept -> MouseClickStatus
        {
            return m_status;
        }

        [[nodiscard]] auto getPoint() const noexcept -> const point&
        {
            return m_point;
        }
    };

    using MouseClickEvent = clsn::core::event<MouseClickData>;
}