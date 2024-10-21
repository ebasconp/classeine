// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/draw/FontStyle.h>

#include <string>
#include <string_view>

namespace clsn::draw
{
    class FontInfo final
    {
        std::string m_name;
        FontStyle m_style;

    public:
        FontInfo(std::string_view name, FontStyle style);

        auto operator==(const FontInfo& oth) const -> bool;

        [[nodiscard]] auto getStyle() const noexcept -> FontStyle;
        [[nodiscard]] auto getName() const noexcept -> const std::string&;
    };
}

template <>
struct std::hash<clsn::draw::FontInfo>
{
    auto operator()(const clsn::draw::FontInfo& fontInfo) const noexcept -> int
    {
        return static_cast<int>(std::hash<std::string>{}(fontInfo.getName()) *
                                    31 +
                                static_cast<int>(fontInfo.getStyle()));
    }
};
