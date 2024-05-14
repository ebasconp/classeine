#pragma once

#include "clsn/core/Property.h"

namespace clsn::ui::models
{
    class ButtonModel
    {
        CLSN_PROPERTY(std::string, true, Text);

    public:
        ButtonModel()
        {
            //addTextChangedListener()
        }
    };
}