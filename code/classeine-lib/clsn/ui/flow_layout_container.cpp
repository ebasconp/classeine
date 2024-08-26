#include "flow_layout_container.h"

#include "renderers/flow_container_renderer.h"


namespace clsn::ui
{
    flow_layout_container::flow_layout_container()
    : layout_container("flow_container")
    {
    }

    auto flow_layout_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::flow_container_renderer>();
    }

}