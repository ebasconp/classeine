// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/ui_manager_defaults.h>
#include <clsn/ui/ui_skin.h>

#include <clsn/draw/font_info.h>

#include <clsn/core/entity.h>

#include <memory>
#include <string>
#include <string_view>

namespace clsn::ui
{
    class ui_manager final : public clsn::core::entity
    {
        std::unique_ptr<ui_skin> m_skin;

        ui_manager_defaults m_defaults;
        std::unordered_map<draw::font_info, std::string> m_paths_by_font_info;

        static std::unique_ptr<ui_manager> m_singleton;

    public:
        ui_manager(const ui_manager&) = delete;
        ui_manager(ui_manager&&) = delete;

        ui_manager& operator=(const ui_manager&) = delete;
        ui_manager& operator=(ui_manager&&) = delete;

        ~ui_manager() override = default;

        static auto get_instance() -> ui_manager&;

        static void run(std::function<void()> proc);
        static void init();
        static void finalize();

        template <typename SkinType>
        void make_and_load_skin()
        {
            m_skin = std::make_unique<SkinType>();
        }

        auto get_renderer_by_control(const control& ctrl) const -> std::shared_ptr<clsn::ui::renderer_base>;

        auto get_color(std::string_view section_name, std::string_view name) const -> const draw::color&;
        auto get_dimension(std::string_view section_name, std::string_view name) const -> const draw::dimension&;
        auto get_font(std::string_view section_name, std::string_view name) const -> const draw::font&;

        void add_font_mapping(const draw::font_info& fontInfo, std::string_view path);
        auto get_path_by_font_info(const draw::font_info&) const noexcept -> std::string_view;

        auto install_theme(const std::string& themeName) -> bool;
        auto add_theme_changed_listener(core::event_listener<core::empty_event> listener) -> int;
        auto get_current_theme_name() const -> const std::string&;

    private:
        ui_manager();

        void populate_defaults();
        void populate_font_mappings();
    };
}