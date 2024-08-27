#include "xy_layout_container.h"

#include "renderers/container_renderer.h"

namespace clsn::ui
{
    xy_layout_container::xy_layout_container()
    : layout_container("xy_layout_container")
    {
    }

    auto xy_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::container_renderer<xy_layout_container>>();
    }
}