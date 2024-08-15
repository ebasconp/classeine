#pragma once

#include "toggle_control.h"

namespace clsn::ui
{
    class check_box : public toggle_control
    {
    public:
        check_box();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;
    };
}