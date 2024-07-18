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

        static auto getInstance() -> UIManager&;
        static void init();
        static void finalize();

        template <typename SkinType>
        void makeAndLoadSkin()
        {
            m_skin = std::make_unique<SkinType>();
        }

        auto getRendererByControl(const Control& ctrl) const -> std::shared_ptr<IRenderer>;

        auto getColor(std::string_view sectionName, std::string_view name) const -> const Color&;
        auto getDimension(std::string_view sectionName, std::string_view name) const -> const Dimension&;
        auto getFont(std::string_view sectionName, std::string_view name) const -> const Font&;

        void addFontMapping(const FontInfo& fontInfo, std::string_view path);
        auto getPathByFontInfo(const FontInfo&) const noexcept -> std::string_view;

        auto installTheme(const std::string& themeName) -> bool;
        auto addThemeChangedListener(EventListener<EmptyEvent> listener) -> int;
        auto getCurrentThemeName() const -> const std::string&;

    private:
        UIManager();

        void populateDefaults();
        void populateFontMappings();
    };
}