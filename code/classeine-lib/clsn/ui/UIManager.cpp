// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "UIManager.h"

#include "clsn/core/Console.h"
#include "clsn/core/System.h"

#include "amatista/AmatistaUISkin.h"


namespace clsn::ui
{
    using namespace clsn::draw;

    std::unique_ptr<UIManager> UIManager::m_singleton;

    UIManager& UIManager::get_instance()
    {
        if (m_singleton == nullptr)
            clsn::core::System::panic(
                "UIManager is not initialized. Run UIManager::init() at the "
                "beginning of your application");

        return *m_singleton;
    }

    void UIManager::init()
    {
        m_singleton = std::unique_ptr<UIManager>(new UIManager());
    }

    void UIManager::finalize()
    {
        m_singleton.reset();
    }

    void UIManager::addFontMapping(const FontInfo& fontInfo,
                                   std::string_view path)
    {
        m_pathsByFontInfo.insert(std::make_pair(fontInfo, std::string{path}));
    }

    UIManager::UIManager()
    {
        clsn::core::Console::debug("UIManager instantiated");

        populateFontMappings();
        populateDefaults();
    }

    void UIManager::populateFontMappings()
    {
        addFontMapping(
            FontInfo{"default", FontStyle::regular}, _CLSN_DEFAULT_FONT_PATH_);

        addFontMapping(
            FontInfo{"bold", FontStyle::bold}, _CLSN_DEFAULT_BOLD_FONT_PATH_);

        addFontMapping(
            FontInfo{"italic", FontStyle::italic}, _CLSN_DEFAULT_ITALIC_FONT_PATH_);

        addFontMapping(
            FontInfo{"bold_italic", FontStyle::bold_italic}, _CLSN_DEFAULT_BOLD_ITALIC_FONT_PATH_);
    }

    void UIManager::populateDefaults()
    {
        using namespace clsn::ui::amatista;

        makeAndLoadSkin<AmatistaUISkin>();
    }

    auto UIManager::getPathByFontInfo(const FontInfo& fontInfo) const noexcept -> std::string_view
    {
        auto it = m_pathsByFontInfo.find(fontInfo);
        if (it == m_pathsByFontInfo.end())
            return "";

        return it->second;
    }

    auto UIManager::getColor(std::string_view sectionName, std::string_view name) const -> const Color&
    {
        return m_skin->getColor(sectionName, name);
    }

    auto UIManager::getDimension(std::string_view sectionName, std::string_view name) const -> const Dimension&
    {
        return m_skin->getDimension(sectionName, name);
    }

    auto UIManager::getFont(std::string_view sectionName, std::string_view name) const -> const Font&
    {
        return m_skin->getFont(sectionName, name);
    }

    auto UIManager::installTheme(const std::string& theme_name) -> bool
    {
        return m_skin->installThemeByName(theme_name);
    }

    auto UIManager::addThemeChangedListener(core::EventListener<core::EmptyEvent> listener) -> int
    {
        return m_skin->addThemeChangedListener(std::move(listener));
    }

    auto UIManager::getCurrentThemeName() const -> const std::string&
    {
        return m_skin->getCurrentThemeName();
    }

    void UIManager::run(std::function<void()> proc)
    {
        clsn::ui::UIManager::init();
        proc();
        clsn::ui::UIManager::finalize();
        clsn::core::Entity::dump();
    }

}