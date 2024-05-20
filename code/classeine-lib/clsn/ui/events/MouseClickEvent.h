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
        explicit MouseClickData(MouseClickStatus status, int x, int y)
        : m_status{status}
        , m_x{x}
        , m_y{y}
        {
        }

        MouseClickStatus getStatus() const noexcept { return m_status; }

        int getX() const noexcept { return m_x; }
        int getY() const noexcept { return m_y; }
    };

    using MouseClickEvent = clsn::core::Event<MouseClickData>;
}