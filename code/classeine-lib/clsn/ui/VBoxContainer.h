#pragma once

#include "Container.h"

#include "controllers/VBoxContainerController.h"
#include "models/BoxContainerModel.h"
#include "renderers/VBoxContainerRenderer.h"

namespace clsn::ui
{
    template <typename Model = models::BoxContainerModel,
              typename Renderer = renderers::VBoxContainerRenderer,
              typename Controller = controllers::VBoxContainerController>
    using BasicVBoxContainer = Container<Model, Renderer, Controller>;

    using VBoxContainer = BasicVBoxContainer<>;
}