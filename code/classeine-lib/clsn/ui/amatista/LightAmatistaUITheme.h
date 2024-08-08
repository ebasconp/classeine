#pragma once

#include "clsn/ui/amatista/AmatistaUITheme.h"

namespace clsn::ui::amatista
{
    class LightAmatistaUITheme final : public AmatistaUITheme
    {
    public:
        LightAmatistaUITheme() = default;

    protected:
        auto getBevelUpColor() const -> color override;
        auto getBevelDownColor() const -> color override;
        auto getContainerBackgroundColor() const -> color override;
        auto getContainerForegroundColor() const -> color override;
        auto getControlBackgroundColor() const -> color override;
        auto getControlForegroundColor() const -> color override;
        auto getControlHoveredBackgroundColor() const -> color override;
        auto getDisabledBackgroundColor() const -> color override;
        auto getDisabledForegroundColor() const -> color override;

        auto getButtonPressedBackgroundColor() const -> color override;
    };
}