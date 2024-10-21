// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "FontStyle.h"

#include <string>
#include <utility>

namespace clsn::draw
{
    class Font
    {
        std::string m_name;
        FontStyle m_style;
        int m_size;

    public:
        Font();

        template <typename StringType>
        Font(StringType&& name, FontStyle style, int size)
        : m_name{std::forward<StringType>(name)}
        , m_style{style}
        , m_size{size}
        {
        }

        [[nodiscard]] auto getName() const noexcept -> const std::string&;
        [[nodiscard]] auto getSize() const noexcept -> int;
        [[nodiscard]] auto getStyle() const noexcept -> FontStyle;

        [[nodiscard]] auto addSize(int size) const noexcept -> Font;

        bool operator==(const Font& Font) const noexcept;
    };
}

template <>
struct std::hash<clsn::draw::Font>
{
    auto operator()(const clsn::draw::Font& Font) const noexcept -> int
    {
        return static_cast<int>(std::hash<std::string>{}(Font.getName()) * 31 +
               static_cast<int>(Font.getStyle()) * 31 + Font.getSize());
    }
};
