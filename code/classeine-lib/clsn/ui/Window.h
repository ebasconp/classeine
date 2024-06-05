#pragma once

#include "Control.h"

#include "clsn/core/Property.h"

#include "clsn/draw/Dimension.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    class Window : public Control
    {
    public:
        explicit Window(std::string_view sectionName);

        CLSN_PROPERTY(MinimumSize, Dimension, true)
        CLSN_BOOL_PROPERTY_VAL(Resizable, true, true);

    private:
        void initDefaults();
        void initVisibility();
    };
}