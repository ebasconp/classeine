// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Control.h>

namespace clsn::ui
{
    /// This class exposes properties for handling background and foreground
    /// Colors, as well as fonts.
    class PaintableControl : public clsn::ui::Control
    {
    public:
        explicit PaintableControl(std::string_view name);

        CLSN_HEADER_PROPERTY(BackgroundColor, std::optional<draw::Color>, true)
        CLSN_HEADER_PROPERTY(Font, std::optional<clsn::draw::Font>, true)
        CLSN_HEADER_PROPERTY(ForegroundColor, std::optional<clsn::draw::Color>, true)

        auto getActualBackgroundColor() const -> const clsn::draw::Color&;
        auto getActualForegroundColor() const -> const clsn::draw::Color&;
        auto getActualFont() const -> const clsn::draw::Font&;

    };
}
