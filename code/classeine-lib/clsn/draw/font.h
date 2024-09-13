// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "font_style.h"

#include <string>
#include <utility>

namespace clsn::draw
{
    class font
    {
        std::string m_name;
        font_style m_style;
        int m_size;

    public:
        font();

        template <typename StringType>
        font(StringType&& name, font_style style, int size)
        : m_name{std::forward<StringType>(name)}
        , m_style{style}
        , m_size{size}
        {
        }

        auto get_name() const noexcept -> const std::string&;
        auto get_size() const noexcept -> int;
        auto get_style() const noexcept -> font_style;

        auto add_size(int size) const noexcept -> font;

        bool operator==(const font& font) const noexcept;
    };
}

template <>
struct std::hash<clsn::draw::font>
{
    auto operator()(const clsn::draw::font& font) const noexcept -> int
    {
        return static_cast<int>(std::hash<std::string>{}(font.get_name()) * 31 +
               static_cast<int>(font.get_style()) * 31 + font.get_size());
    }
};
