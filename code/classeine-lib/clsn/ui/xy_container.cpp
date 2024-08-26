#include "xy_container.h"

#include "renderers/xy_container_renderer.h"

namespace clsn::ui
{
    xy_container::xy_container()
    : list_container("xy_container")
    {
    }

    auto xy_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::xy_container_renderer>();
    }
}