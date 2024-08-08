#pragma once

#include "clsn/core/configuration.h"

#include "clsn/draw/color.h"
#include "clsn/draw/dimension.h"
#include "clsn/draw/font.h"

#include <memory>

namespace clsn::ui
{
    using UIManagerDefaults = clsn::core::configuration<clsn::draw::color,
                                                        clsn::draw::dimension,
                                                        clsn::draw::font>;
}