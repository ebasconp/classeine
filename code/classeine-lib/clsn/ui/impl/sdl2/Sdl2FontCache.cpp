#include "Sdl2FontCache.h"

#include "clsn/ui/UIManager.h"

#include "clsn/draw/FontInfo.h"

namespace clsn::ui::impl::sdl2
{
    OptionalTTFFontRef Sdl2FontCache::getFont(const clsn::draw::Font& font) const
    {
        auto it = m_fonts.find(font);
        if (it != m_fonts.end())
            return *it->second;

        auto& uim = UIManager::getInstance();
        auto path = uim.getPathByFontInfo(FontInfo{font.getName(), font.getStyle()});
        if (path.empty())
            return std::nullopt;

        TTF_Font* actualFont = TTF_OpenFont(path.data(), font.getSize());
        if (actualFont == nullptr)
            return std::nullopt;

        m_fonts.insert(std::make_pair(font, Sdl2FontWrapper{actualFont}));
        return *actualFont;
    }
}