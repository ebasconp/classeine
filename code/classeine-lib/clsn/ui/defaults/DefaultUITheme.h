#pragma once

#include "clsn/ui/UITheme.h"

namespace clsn::ui::defaults
{
    class DefaultUITheme : public UITheme
    {
    public:
        DefaultUITheme() = default;

        void populateDefaults() final;
        
    protected:
        virtual auto getDefaultFont() const -> Font;
        virtual auto getButtonPreferredSize() const -> Dimension;

        virtual auto getBevelUpColor() const -> Color = 0;
        virtual auto getBevelDownColor() const -> Color = 0;
        virtual auto getContainerBackgroundColor() const -> Color = 0;
        virtual auto getContainerForegroundColor() const -> Color = 0;
        virtual auto getControlBackgroundColor() const -> Color = 0;
        virtual auto getControlForegroundColor() const -> Color = 0;
        virtual auto getDisabledBackgroundColor() const -> Color = 0;
        virtual auto getDisabledForegroundColor() const -> Color = 0;

        virtual auto getButtonPressedBackgroundColor() const -> Color = 0;

    };
}