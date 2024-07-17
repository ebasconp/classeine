#pragma once

#include "clsn/ui/UITheme.h"

namespace clsn::ui::defaults
{
    class DefaultDarkUITheme final : public UITheme
    {
    public:
        DefaultDarkUITheme() = default;

        void populateDefaults() override;
    };
}