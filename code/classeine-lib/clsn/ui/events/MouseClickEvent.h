#pragma once

#include "clsn/core/Event.h"

namespace clsn::ui::events
{
    enum class MouseClickStatus
    {
        released,
        pressed
    };

    class MouseClickData
    {
    private:
        MouseClickStatus m_status;
        int m_x;
        int m_y;

    public:
        MouseClickData(MouseClickStatus status, int x, int y)
        : m_status{status}
        , m_x{x}
        , m_y{y}
        {
        }

        auto getStatus() const noexcept -> MouseClickStatus { return m_status; }

        auto getX() const noexcept -> int { return m_x; }
        auto getY() const noexcept -> int { return m_y; }
    };

    using MouseClickEvent = clsn::core::Event<MouseClickData>;
}