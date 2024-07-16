#pragma once

#include "UIManagerDefaults.h"
#include "UISkin.h"

#include "clsn/draw/FontInfo.h"

#include "clsn/core/Entity.h"

#include <memory>
#include <string>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::draw;

    class UIManager final : public Entity
    {
        std::unique_ptr<UISkin> m_skin;

        UIManagerDefaults m_defaults;
        std::unordered_map<FontInfo, std::string> m_pathsByFontInfo;

        static std::unique_ptr<UIManager> m_singleton;

    public:
        UIManager(const UIManager&) = delete;
        UIManager(UIManager&&) = delete;

        UIManager& operator=(const UIManager&) = delete;
        UIManager& operator=(UIManager&&) = delete;

        ~UIManager() override = default;

        static UIManager& getInstance();
        static void init();
        static void finalize();

        template <typename SkinType>
        void makeAndLoadSkin()
        {
            m_skin = std::make_unique<SkinType>();
        }

        std::shared_ptr<IRenderer> getRendererByControl(const Control& ctrl) const;

        const Color& getColor(std::string_view sectionName, std::string_view name) const;

        // ETOTODO: MOVE THIS TO THE THEME
        const Font& getDefaultFont() const
        {
            static Font font{"Nimbus", FontStyle::REGULAR, 14};

            return font;
        }

        void addFontMapping(const FontInfo& fontInfo, std::string_view path);
        std::string_view getPathByFontInfo(const FontInfo&) const noexcept;

        auto installTheme(const std::string& themeName) -> bool;

    private:
        UIManager();

        void populateDefaults();
        void populateFontMappings();
    };
}