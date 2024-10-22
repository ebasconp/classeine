// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/UIManagerDefaults.h>
#include <clsn/ui/UISkin.h>

#include "clsn/draw/FontInfo.h"

#include "clsn/core/Entity.h"

#include <memory>
#include <string>
#include <string_view>

namespace clsn::ui
{
    class UIManager final : public clsn::core::Entity
    {
        std::unique_ptr<UISkin> m_skin;

        UIManagerDefaults m_defaults;
        std::unordered_map<draw::FontInfo, std::string> m_pathsByFontInfo;

        static std::unique_ptr<UIManager> m_singleton;

    public:
        UIManager(const UIManager&) = delete;
        UIManager(UIManager&&) = delete;

        UIManager& operator=(const UIManager&) = delete;
        UIManager& operator=(UIManager&&) = delete;

        ~UIManager() override = default;

        static auto get_instance() -> UIManager&;

        static void run(std::function<void()> proc);
        static void init();
        static void finalize();

        template <typename SkinType>
        void makeAndLoadSkin()
        {
            m_skin = std::make_unique<SkinType>();
        }

        auto getColor(std::string_view sectionName, std::string_view name) const -> const draw::Color&;
        auto getDimension(std::string_view sectionName, std::string_view name) const -> const draw::Dimension&;
        auto getFont(std::string_view sectionName, std::string_view name) const -> const draw::Font&;

        void addFontMapping(const draw::FontInfo& fontInfo, std::string_view path);
        auto getPathByFontInfo(const draw::FontInfo&) const noexcept -> std::string_view;

        auto installTheme(const std::string& themeName) -> bool;
        auto addThemeChangedListener(core::EventListener<core::EmptyEvent> listener) -> int;
        auto getCurrentThemeName() const -> const std::string&;

    private:
        UIManager();

        void populateDefaults();
        void populateFontMappings();
    };
}