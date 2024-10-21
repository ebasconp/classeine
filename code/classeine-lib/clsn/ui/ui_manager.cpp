// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include "ui_manager.h"

#include "clsn/core/Console.h"
#include "clsn/core/System.h"

#include "amatista/amatista_ui_skin.h"


namespace clsn::ui
{
    using namespace clsn::draw;

    std::unique_ptr<ui_manager> ui_manager::m_singleton;

    ui_manager& ui_manager::get_instance()
    {
        if (m_singleton == nullptr)
            clsn::core::System::panic(
                "ui_manager is not initialized. Run ui_manager::init() at the "
                "beginning of your application");

        return *m_singleton;
    }

    void ui_manager::init()
    {
        m_singleton = std::unique_ptr<ui_manager>(new ui_manager());
    }

    void ui_manager::finalize()
    {
        m_singleton.reset();
    }

    void ui_manager::add_font_mapping(const FontInfo& fontInfo,
                                   std::string_view path)
    {
        m_paths_by_font_info.insert(std::make_pair(fontInfo, std::string{path}));
    }

    ui_manager::ui_manager()
    {
        clsn::core::Console::debug("ui_manager instantiated");

        populate_font_mappings();
        populate_defaults();
    }

    void ui_manager::populate_font_mappings()
    {
        add_font_mapping(
            FontInfo{"default", FontStyle::regular}, _CLSN_DEFAULT_FONT_PATH_);

        add_font_mapping(
            FontInfo{"bold", FontStyle::bold}, _CLSN_DEFAULT_BOLD_FONT_PATH_);

        add_font_mapping(
            FontInfo{"italic", FontStyle::italic}, _CLSN_DEFAULT_ITALIC_FONT_PATH_);

        add_font_mapping(
            FontInfo{"bold_italic", FontStyle::bold_italic}, _CLSN_DEFAULT_BOLD_ITALIC_FONT_PATH_);
    }

    void ui_manager::populate_defaults()
    {
        using namespace clsn::ui::amatista;

        make_and_load_skin<amatista_ui_skin>();
    }

    auto ui_manager::get_path_by_font_info(const FontInfo& fontInfo) const noexcept -> std::string_view
    {
        auto it = m_paths_by_font_info.find(fontInfo);
        if (it == m_paths_by_font_info.end())
            return "";

        return it->second;
    }

    auto ui_manager::getColor(std::string_view sectionName, std::string_view name) const -> const Color&
    {
        return m_skin->getColor(sectionName, name);
    }

    auto ui_manager::get_dimension(std::string_view sectionName, std::string_view name) const -> const Dimension&
    {
        return m_skin->get_dimension(sectionName, name);
    }

    auto ui_manager::getFont(std::string_view sectionName, std::string_view name) const -> const Font&
    {
        return m_skin->getFont(sectionName, name);
    }

    auto ui_manager::install_theme(const std::string& theme_name) -> bool
    {
        return m_skin->install_theme_by_name(theme_name);
    }

    auto ui_manager::add_theme_changed_listener(core::EventListener<core::EmptyEvent> listener) -> int
    {
        return m_skin->add_theme_changed_listener(std::move(listener));
    }

    auto ui_manager::get_current_theme_name() const -> const std::string&
    {
        return m_skin->get_current_theme_name();
    }

    void ui_manager::run(std::function<void()> proc)
    {
        clsn::ui::ui_manager::init();
        proc();
        clsn::ui::ui_manager::finalize();
        clsn::core::Entity::dump();
    }

}