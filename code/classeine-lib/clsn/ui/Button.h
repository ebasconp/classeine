#pragma once

#include "Control.h"

#include "controllers/ButtonController.h"
#include "models/ButtonModel.h"
#include "renderers/ButtonRenderer.h"

namespace clsn::ui
{
    template <typename Model = models::DefaultButtonModel,
              typename Renderer = renderers::DefaultButtonRenderer,
              typename Controller = controllers::ButtonController>
    using Button = Control<Model, Renderer, Controller>;

    using DefaultButton = Button<>;
}