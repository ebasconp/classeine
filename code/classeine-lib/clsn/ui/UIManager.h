#pragma once

#include "UIManagerDefaults.h"
#include "UISkin.h"

#include "clsn/draw/font_info.h"

#include "clsn/core/entity.h"

#include <memory>
#include <string>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::draw;

    class UIManager final : public entity
    {
        std::unique_ptr<UISkin> m_skin;

        UIManagerDefaults m_defaults;
        std::unordered_map<font_info, std::string> m_pathsByFontInfo;

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

        auto getRendererByControl(const control& ctrl) const -> std::shared_ptr<IRenderer>;

        auto getColor(std::string_view section_name, std::string_view name) const -> const color&;
        auto getDimension(std::string_view section_name, std::string_view name) const -> const dimension&;
        auto get_font(std::string_view section_name, std::string_view name) const -> const font&;

        void addFontMapping(const font_info& fontInfo, std::string_view path);
        auto getPathByFontInfo(const font_info&) const noexcept -> std::string_view;

        auto installTheme(const std::string& themeName) -> bool;
        auto addThemeChangedListener(event_listener<empty_event> listener) -> int;
        auto getCurrentThemeName() const -> const std::string&;

    private:
        UIManager();

        void populateDefaults();
        void populateFontMappings();
    };
}