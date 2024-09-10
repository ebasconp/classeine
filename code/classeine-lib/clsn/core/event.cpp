#include "event.h"

namespace clsn::core
{
    event::event()
    : m_consumed{false}
    {
    }

    auto event::is_consumed() const noexcept -> bool
    {
        return m_consumed;
    }

    void event::consume()
    {
        m_consumed = true;
    }
}