#pragma once

#include "Container.h"

#include "controllers/HBoxContainerController.h"
#include "models/BoxContainerModel.h"
#include "renderers/HBoxContainerRenderer.h"

namespace clsn::ui
{
    template <typename Model = models::BoxContainerModel,
              typename Renderer = renderers::HBoxContainerRenderer,
              typename Controller = controllers::HBoxContainerController>
    using BasicHBoxContainer = Container<Model, Renderer, Controller>;

    using HBoxContainer = BasicHBoxContainer<>;
}