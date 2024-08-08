#pragma once

#include "clsn/core/configuration.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Font.h"

#include <memory>

namespace clsn::ui
{
    using UIManagerDefaults = clsn::core::configuration<clsn::draw::Color,
                                                        clsn::draw::Dimension,
                                                        clsn::draw::Font>;
}