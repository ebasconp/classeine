#include "Sdl2FontCache.h"

#include "clsn/ui/UIManager.h"

#include "clsn/draw/font_info.h"

namespace clsn::ui::impl::sdl2
{
    OptionalTTFFontRef Sdl2FontCache::get_font(const clsn::draw::font& font) const
    {
        auto it = m_fonts.find(font);
        if (it != m_fonts.end())
            return *it->second;

        auto& uim = UIManager::getInstance();
        auto path = uim.getPathByFontInfo(font_info{font.get_name(), font.get_style()});
        if (path.empty())
            return std::nullopt;

        TTF_Font* actualFont = TTF_OpenFont(path.data(), font.get_size());
        if (actualFont == nullptr)
            return std::nullopt;

        m_fonts.insert(std::make_pair(font, Sdl2FontWrapper{actualFont}));
        return *actualFont;
    }
}