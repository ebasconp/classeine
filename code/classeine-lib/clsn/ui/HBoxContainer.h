#pragma once

#include "Control.h"

#include "controllers/HBoxContainerController.h"
#include "models/BoxContainerModel.h"
#include "renderers/HBoxContainerRenderer.h"

namespace clsn::ui
{
    template <typename Model = models::BoxContainerModel,
              typename Renderer = renderers::HBoxContainerRenderer,
              typename Controller = controllers::HBoxContainerController>
    using HBoxContainer = Control<Model, Renderer, Controller>;

    using DefaultHBoxContainer = HBoxContainer<>;
}