#pragma once

#include "clsn/core/Configuration.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Font.h"

#include "clsn/ui/renderers/IRenderer.h"

#include <memory>

namespace clsn::ui
{
    using clsn::ui::renderers::IRenderer;

    using UIManagerDefaults = clsn::core::Configuration<clsn::draw::Color,
                                                        clsn::draw::Dimension,
                                                        clsn::draw::Font,
                                                        std::shared_ptr<IRenderer>>;
}