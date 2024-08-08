#pragma once

#include "clsn/ui/ui_theme.h"

namespace clsn::ui::amatista
{
    class AmatistaUITheme : public ui_theme
    {
    public:
        AmatistaUITheme() = default;

        void populate_defaults() final;
        
    protected:
        virtual auto getDefaultFont() const -> font;
        virtual auto getButtonPreferredSize() const -> dimension;

        virtual auto getBevelUpColor() const -> color = 0;
        virtual auto getBevelDownColor() const -> color = 0;
        virtual auto getContainerBackgroundColor() const -> color = 0;
        virtual auto getContainerForegroundColor() const -> color = 0;
        virtual auto getControlBackgroundColor() const -> color = 0;
        virtual auto getControlForegroundColor() const -> color = 0;
        virtual auto getControlHoveredBackgroundColor() const -> color = 0;
        virtual auto getDisabledBackgroundColor() const -> color = 0;
        virtual auto getDisabledForegroundColor() const -> color = 0;

        virtual auto getButtonPressedBackgroundColor() const -> color = 0;

    };
}