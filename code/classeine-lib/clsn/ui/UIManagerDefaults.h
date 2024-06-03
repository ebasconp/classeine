#pragma once

#include "clsn/core/Configuration.h"
#include "clsn/core/Lazy.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Font.h"

#include "clsn/ui/IRenderer.h"

#include <memory>

namespace clsn::ui
{
    using clsn::ui::IRenderer;

    using LazyRenderer = Lazy<std::shared_ptr<IRenderer>>;

    template <typename RendererType>
    LazyRenderer makeLazyRenderer()
    {
        return LazyRenderer
        {
            []() { return std::make_shared<RendererType>(); }
        };
    }

    using UIManagerDefaults = clsn::core::Configuration<clsn::draw::Color,
                                                        clsn::draw::Dimension,
                                                        clsn::draw::Font,
                                                        LazyRenderer>;
}