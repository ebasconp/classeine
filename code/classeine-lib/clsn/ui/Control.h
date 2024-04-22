#pragma once

#include "clsn/core/Property.h"
#include "clsn/draw/Dimension.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    template <typename Model, typename EventManager, typename Renderer>
    class Control : public Model, public EventManager, public Renderer
    {
        CLSN_PROPERTY_VAL(Dimension, true, Size, (Dimension{600, 400}));
        CLSN_PROPERTY_VAL(bool, true, Visible, true);
    };
}