#pragma once

#include "clickable_control.h"

namespace clsn::ui
{
    class button : public clickable_control
    {
    public:
        button();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}