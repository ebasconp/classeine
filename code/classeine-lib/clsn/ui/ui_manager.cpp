#include "ui_manager.h"

#include "clsn/core/system.h"

#include "amatista/amatista_ui_skin.h"

#include <iostream> //ETOTODO: Remove

namespace clsn::ui
{
    std::unique_ptr<ui_manager> ui_manager::m_singleton;

    ui_manager& ui_manager::get_instance()
    {
        if (m_singleton == nullptr)
            clsn::core::system::panic(
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

    void ui_manager::add_font_mapping(const font_info& fontInfo,
                                   std::string_view path)
    {
        m_paths_by_font_info.insert(std::make_pair(fontInfo, std::string{path}));
    }

    ui_manager::ui_manager()
    {
        std::cout << "ui_manager instantiated" << std::endl;

        populate_font_mappings();
        populate_defaults();
    }

    void ui_manager::populate_font_mappings()
    {
        add_font_mapping(
            font_info{"Nimbus", font_style::regular},
            "/usr/share/fonts/opentype/urw-base35/NimbusSans-Regular.otf");
    }

    void ui_manager::populate_defaults()
    {
        using namespace clsn::ui::amatista;

        make_and_load_skin<amatista_ui_skin>();
    }

    auto ui_manager::get_path_by_font_info(const font_info& fontInfo) const noexcept -> std::string_view
    {
        auto it = m_paths_by_font_info.find(fontInfo);
        if (it == m_paths_by_font_info.end())
            return "";

        return it->second;
    }

    auto ui_manager::get_renderer_by_control(const control& ctrl) const -> std::shared_ptr<renderer_base>
    {
        return m_skin->get_renderer_by_control(ctrl);
    }

    auto ui_manager::get_color(std::string_view section_name, std::string_view name) const -> const color&
    {
        return m_skin->get_color(section_name, name);
    }

    auto ui_manager::get_dimension(std::string_view section_name, std::string_view name) const -> const dimension&
    {
        return m_skin->get_dimension(section_name, name);
    }

    auto ui_manager::get_font(std::string_view section_name, std::string_view name) const -> const font&
    {
        return m_skin->get_font(section_name, name);
    }

    auto ui_manager::install_theme(const std::string& themeName) -> bool
    {
        return m_skin->install_theme_by_name(themeName);
    }

    auto ui_manager::add_theme_changed_listener(event_listener<empty_event> listener) -> int
    {
        return m_skin->add_theme_changed_listener(listener);
    }

    auto ui_manager::get_current_theme_name() const -> const std::string&
    {
        return m_skin->get_current_theme_name();
    }
}