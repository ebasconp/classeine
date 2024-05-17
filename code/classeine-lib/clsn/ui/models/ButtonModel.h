#pragma once

#include "clsn/core/Property.h"

namespace clsn::ui::models
{
    class DefaultButtonModel
    {
        CLSN_PROPERTY(std::string, true, Text);
    };
}