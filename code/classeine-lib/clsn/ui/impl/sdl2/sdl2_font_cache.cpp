// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "sdl2_font_cache.h"

#include "clsn/ui/ui_manager.h"

#include "clsn/draw/font_info.h"

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    optional_ttf_font_ref sdl2_font_cache::getFont(const clsn::draw::font& font) const
    {
        auto it = m_fonts.find(font);
        if (it != m_fonts.end())
            return *it->second;

        auto& uim = ui_manager::get_instance();
        auto path = uim.get_path_by_font_info(font_info{font.getName(), font.get_style()});
        if (path.empty())
            return std::nullopt;

        TTF_Font* actualFont = TTF_OpenFont(path.data(), font.getSize());
        if (actualFont == nullptr)
            return std::nullopt;

        m_fonts.insert(std::make_pair(font, sdl2_font_wrapper{actualFont}));
        return *actualFont;
    }
}