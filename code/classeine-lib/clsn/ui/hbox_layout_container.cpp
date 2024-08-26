#include "hbox_layout_container.h"

#include "renderers/hbox_layout_container_renderer.h"

namespace clsn::ui
{
    hbox_layout_container::hbox_layout_container()
    : layout_container("hbox_layout_container")
    {
    }

    auto hbox_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::hbox_layout_container_renderer>();
    }
}