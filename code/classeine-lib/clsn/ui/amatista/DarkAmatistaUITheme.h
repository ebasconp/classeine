// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "clsn/ui/amatista/AmatistaUITheme.h"

namespace clsn::ui::amatista
{
    class DarkAmatistaUITheme final : public AmatistaUITheme
    {
    public:
        DarkAmatistaUITheme() = default;

    protected:
        auto getBevelUpColor() const -> draw::Color override;
        auto getBevelDownColor() const -> draw::Color override;
        auto getContainerBackgroundColor() const -> draw::Color override;
        auto getContainerForegroundColor() const -> draw::Color override;
        auto getControlBackgroundColor() const -> draw::Color override;
        auto getControlForegroundColor() const -> draw::Color override;
        auto getControlHoveredBackgroundColor() const -> draw::Color override;
        auto getDisabledBackgroundColor() const -> draw::Color override;
        auto getDisabledForegroundColor() const -> draw::Color override;

        auto getButtonPressedBackgroundColor() const -> draw::Color override;
    };
}