// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/UITheme.h"

namespace clsn::ui::amatista
{
    class AmatistaUITheme : public UITheme
    {
    public:
        AmatistaUITheme() = default;

        void populateDefaults() final;

    protected:
        virtual auto getDefaultRegularFont() const -> draw::Font;
        virtual auto getDefaultBoldFont() const -> draw::Font;
        virtual auto getDefaultItalicFont() const -> draw::Font;
        virtual auto getDefaultBoldItalicFont() const -> draw::Font;

        virtual auto getButtonPreferredSize() const -> draw::Dimension;

        virtual auto getBevelUpColor() const -> draw::Color = 0;
        virtual auto getBevelDownColor() const -> draw::Color = 0;
        virtual auto getContainerBackgroundColor() const -> draw::Color = 0;
        virtual auto getContainerForegroundColor() const -> draw::Color = 0;
        virtual auto getControlBackgroundColor() const -> draw::Color = 0;
        virtual auto getControlForegroundColor() const -> draw::Color = 0;
        virtual auto getControlHoveredBackgroundColor() const -> draw::Color = 0;
        virtual auto getDisabledBackgroundColor() const -> draw::Color = 0;
        virtual auto getDisabledForegroundColor() const -> draw::Color = 0;

        virtual auto getButtonPressedBackgroundColor() const -> draw::Color = 0;

    };
}