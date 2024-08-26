#include "vbox_layout_container.h"

#include "renderers/vbox_container_renderer.h"


namespace clsn::ui
{
    vbox_layout_container::vbox_layout_container()
    : layout_container("vbox_layout_container")
    {
    }

    auto vbox_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::vbox_container_renderer>();
    }
}