#pragma once

#include "clsn/core/Event.h"

#include "clsn/draw/Point.h"

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
        Point m_point;

    public:
        MouseClickData(MouseClickStatus status, const Point& point)
        : m_status{status}
        , m_point{point}
        {
        }

        [[nodiscard]] auto getStatus() const noexcept -> MouseClickStatus
        {
            return m_status;
        }

        [[nodiscard]] auto getPoint() const noexcept -> const Point&
        {
            return m_point;
        }
    };

    using MouseClickEvent = clsn::core::Event<MouseClickData>;
}