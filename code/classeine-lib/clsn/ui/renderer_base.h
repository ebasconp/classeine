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

        virtual void paint(graphics& a_graphics,
                           const region& region,
                           const control& baseControl) const = 0;
    };
}