#pragma once

#include "Control.h"

#include "controllers/ButtonController.h"
#include "models/ButtonModel.h"
#include "renderers/ButtonRenderer.h"

namespace clsn::ui
{
    using Button = Control<
                        models::DefaultButtonModel,
                        renderers::DefaultButtonRenderer,
                        controllers::ButtonController
                        >;
}