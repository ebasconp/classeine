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

    public:
        explicit MouseClickData(MouseClickStatus status)
        : m_status{status}
        {
        }

        MouseClickStatus getStatus() const noexcept { return m_status; }
    };

    using MouseClickEvent = clsn::core::Event<MouseClickData>;
}