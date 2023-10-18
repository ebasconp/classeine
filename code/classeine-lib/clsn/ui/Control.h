#pragma once

#include "clsn/gfx/Dimension.h"


namespace clsn::ui
{
    class Control
    {
    public:
        Control();
        virtual ~Control() = default;

    private:
        clsn::gfx::Dimension m_size;
    };
}