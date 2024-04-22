#pragma once

#include "Control.h"

#include "models/ButtonModel.h"
#include "events/ActionEventManager.h"
#include "renderers/ButtonRenderer.h"

namespace clsn::ui
{
    using Button = Control<
                        models::ButtonModel,
                        events::ActionEventManager,
                        renderers::ButtonRenderer>;
}