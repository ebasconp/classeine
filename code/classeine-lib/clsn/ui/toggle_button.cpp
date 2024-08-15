#include "toggle_button.h"

#include "renderers/toggle_button_renderer.h"

namespace clsn::ui
{
    toggle_button::toggle_button()
    : toggle_control("toggle_button")
    {

    }

    auto toggle_button::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::toggle_button_renderer>();
    }
}