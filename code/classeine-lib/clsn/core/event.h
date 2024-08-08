#pragma once

#include <utility>

namespace clsn::core
{
    template <typename Data>
    class event final : public Data
    {
        bool m_consumed;

    public:
        template <typename... Args>
        explicit event(Args&&... args)
        : Data{std::forward<Args>(args)...}
        , m_consumed{false}
        {
        }

        [[nodiscard]] auto is_consumed() const noexcept -> bool
        {
            return m_consumed;
        }

        void consume() { m_consumed = true; }
    };
}