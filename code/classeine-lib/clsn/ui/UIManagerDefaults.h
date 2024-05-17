#pragma once

#include "clsn/core/Configuration.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Font.h"

namespace clsn::ui
{
    using UIManagerDefaults =
        clsn::core::Configuration<clsn::draw::Color, clsn::draw::Font>;
}