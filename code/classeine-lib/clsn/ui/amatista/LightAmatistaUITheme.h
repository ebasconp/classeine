#pragma once

#include "clsn/ui/amatista/AmatistaUITheme.h"

namespace clsn::ui::amatista
{
    class LightAmatistaUITheme final : public AmatistaUITheme
    {
    public:
        LightAmatistaUITheme() = default;

    protected:
        auto getBevelUpColor() const -> Color override;
        auto getBevelDownColor() const -> Color override;
        auto getContainerBackgroundColor() const -> Color override;
        auto getContainerForegroundColor() const -> Color override;
        auto getControlBackgroundColor() const -> Color override;
        auto getControlForegroundColor() const -> Color override;
        auto getControlHoveredBackgroundColor() const -> Color override;
        auto getDisabledBackgroundColor() const -> Color override;
        auto getDisabledForegroundColor() const -> Color override;

        auto getButtonPressedBackgroundColor() const -> Color override;
    };
}