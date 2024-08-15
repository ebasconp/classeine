#pragma once

#include "control.h"

namespace clsn::ui
{
    class label : public control
    {
    public:
        label();

    protected:
        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;

    };
}