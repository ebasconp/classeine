#pragma once

#include "entity.h"

namespace clsn::core
{
    class event : public entity
    {
        bool m_consumed;

    public:
        virtual ~event() = default;

        [[nodiscard]] auto is_consumed() const noexcept -> bool;

        void consume();

    protected:
        event();
    };
}