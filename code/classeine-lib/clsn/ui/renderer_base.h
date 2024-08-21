#pragma once

#include "clsn/core/entity.h"

#include "clsn/ui/graphics.h"

namespace clsn::draw
{
    class region;
}

namespace clsn::ui
{
    class control;
}

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    class renderer_base : public entity
    {
    public:
        ~renderer_base() override = default;

        virtual void paint(graphics& gfx,
                           const region& rgn,
                           const control& ctrl) const = 0;
    };
}