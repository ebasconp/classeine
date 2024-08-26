#include "hbox_container.h"

#include "renderers/hbox_container_renderer.h"

namespace clsn::ui
{
    hbox_container::hbox_container()
    : layout_container("hbox_container")
    {
    }

    auto hbox_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::hbox_container_renderer>();
    }
}