// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "sdl2_font_cache.h"

#include "clsn/ui/ui_manager.h"

#include "clsn/draw/FontInfo.h"

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    optional_ttf_font_ref sdl2_font_cache::getFont(const clsn::draw::Font& Font) const
    {
        auto it = m_fonts.find(Font);
        if (it != m_fonts.end())
            return *it->second;

        auto& uim = ui_manager::get_instance();
        auto path = uim.get_path_by_font_info(FontInfo{Font.getName(), Font.getStyle()});
        if (path.empty())
            return std::nullopt;

        TTF_Font* actualFont = TTF_OpenFont(path.data(), Font.getSize());
        if (actualFont == nullptr)
            return std::nullopt;

        m_fonts.insert(std::make_pair(Font, sdl2_font_wrapper{actualFont}));
        return *actualFont;
    }
}