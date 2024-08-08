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

    class IRenderer : public entity
    {
    public:
        ~IRenderer() override = default;

        virtual void paint(graphics& graphics,
                           const region& region,
                           const control& baseControl) const = 0;
    };
}