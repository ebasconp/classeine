#include "flow_container.h"

#include "renderers/flow_container_renderer.h"


namespace clsn::ui
{
    flow_container::flow_container()
    : list_container("flow_container")
    {
    }

    auto flow_container::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::flow_container_renderer>();
    }

}