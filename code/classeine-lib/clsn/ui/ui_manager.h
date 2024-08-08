#pragma once

#include "ui_manager_defaults.h"
#include "ui_skin.h"

#include "clsn/draw/font_info.h"

#include "clsn/core/entity.h"

#include <memory>
#include <string>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::draw;

    class ui_manager final : public entity
    {
        std::unique_ptr<ui_skin> m_skin;

        ui_manager_defaults m_defaults;
        std::unordered_map<font_info, std::string> m_paths_by_font_info;

        static std::unique_ptr<ui_manager> m_singleton;

    public:
        ui_manager(const ui_manager&) = delete;
        ui_manager(ui_manager&&) = delete;

        ui_manager& operator=(const ui_manager&) = delete;
        ui_manager& operator=(ui_manager&&) = delete;

        ~ui_manager() override = default;

        static auto get_instance() -> ui_manager&;
        static void init();
        static void finalize();

        template <typename SkinType>
        void make_and_load_skin()
        {
            m_skin = std::make_unique<SkinType>();
        }

        auto get_renderer_by_control(const control& ctrl) const -> std::shared_ptr<IRenderer>;

        auto get_color(std::string_view section_name, std::string_view name) const -> const color&;
        auto get_dimension(std::string_view section_name, std::string_view name) const -> const dimension&;
        auto get_font(std::string_view section_name, std::string_view name) const -> const font&;

        void add_font_mapping(const font_info& fontInfo, std::string_view path);
        auto get_path_by_font_info(const font_info&) const noexcept -> std::string_view;

        auto install_theme(const std::string& themeName) -> bool;
        auto add_theme_changed_listener(event_listener<empty_event> listener) -> int;
        auto get_current_theme_name() const -> const std::string&;

    private:
        ui_manager();

        void populate_defaults();
        void populate_font_mappings();
    };
}