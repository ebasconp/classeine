#pragma once

#include <utility>

namespace clsn::core
{
    template <typename Data>
    class Event final : public Data
    {
        bool m_consumed;

    public:
        template <typename... Args>
        explicit Event(Args&&... args)
        : Data{std::forward<Args>(args)...}
        , m_consumed{false}
        {
        }

        [[nodiscard]] auto isConsumed() const noexcept -> bool
        {
            return m_consumed;
        }

        void consume() { m_consumed = true; }
    };
}