#include "vbox_container.h"

#include "renderers/vbox_container_renderer.h"


namespace clsn::ui
{
    vbox_container::vbox_container()
    : list_container("vbox_container")
    {
    }

    auto vbox_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::vbox_container_renderer>();
    }
}