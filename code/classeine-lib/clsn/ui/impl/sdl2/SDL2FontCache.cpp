// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/impl/sdl2/SDL2FontCache.h>

#include <clsn/ui/UIManager.h>

#include <clsn/draw/FontInfo.h>

namespace clsn::ui::impl::sdl2
{
    using namespace clsn::draw;

    optional_ttf_font_ref SDL2FontCache::getFont(const clsn::draw::Font& Font) const
    {
        auto it = m_fonts.find(Font);
        if (it != m_fonts.end())
            return *it->second;

        auto& uim = UIManager::get_instance();
        auto path = uim.getPathByFontInfo(FontInfo{Font.getName(), Font.getStyle()});
        if (path.empty())
            return std::nullopt;

        TTF_Font* actualFont = TTF_OpenFont(path.data(), Font.getSize());
        if (actualFont == nullptr)
            return std::nullopt;

        m_fonts.insert(std::make_pair(Font, SDL2FontWrapper{actualFont}));
        return *actualFont;
    }
}