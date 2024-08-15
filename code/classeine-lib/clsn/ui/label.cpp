#include "label.h"

#include "renderers/label_renderer.h"

namespace clsn::ui
{
    label::label()
    : control{"label"}
    {
    }

    auto label::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::label_renderer>();
    }
}