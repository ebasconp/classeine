#include "button.h"

#include "renderers/button_renderer.h"

namespace clsn::ui
{
    button::button()
    : clickable_control("button")
    {
    }

    auto button::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::button_renderer>();
    }
}