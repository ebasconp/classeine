#pragma once

#include "Control.h"


namespace clsn::ui
{
    template <typename Model, typename Renderer, typename Controller>
    class Container final : public Control<Model, Renderer, Controller>
    {
    public:
        using Control<Model, Renderer, Controller>::Control;
    };
}