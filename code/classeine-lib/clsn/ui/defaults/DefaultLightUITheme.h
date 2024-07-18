#pragma once

#include "clsn/ui/defaults/DefaultUITheme.h"

namespace clsn::ui::defaults
{
    class DefaultLightUITheme final : public DefaultUITheme
    {
    public:
        DefaultLightUITheme() = default;

    protected:
        auto getBevelUpColor() const -> Color override;
        auto getBevelDownColor() const -> Color override;
        auto getContainerBackgroundColor() const -> Color override;
        auto getContainerForegroundColor() const -> Color override;
        auto getControlBackgroundColor() const -> Color override;
        auto getControlForegroundColor() const -> Color override;
        auto getDisabledBackgroundColor() const -> Color override;
        auto getDisabledForegroundColor() const -> Color override;

        auto getButtonPressedBackgroundColor() const -> Color override;
    };
}