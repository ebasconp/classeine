// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "window.h"

#include "impl/main_window_impl.h"

namespace clsn::ui
{
    template <typename ControlType>
    class main_window : public window
    {
        clsn::ui::impl::main_window_impl<main_window<ControlType>> m_impl;
        ControlType m_control;

    public:
        main_window()
        : window("main_window")
        , m_impl{*this}
        {
            init_main_window_visibility();
            init_size();
            load_window_defaults();

            ui_manager::get_instance().add_theme_changed_listener([this](auto&)
            {
                update_theme();
            });

            m_control.set_parent_window(*this);
            m_control.set_parent_control(*this);
        }

        [[nodiscard]] auto operator()() noexcept -> ControlType&
        {
            return m_control;
        }

        [[nodiscard]] auto operator()() const noexcept -> const ControlType&
        {
            return m_control;
        }

        void process_mouse_click_event(events::mouse_click_event& e) override
        {
            m_control.notify_mouse_click_event(e);
        }

        void process_mouse_moved_event(events::mouse_moved_event& e) override
        {
            window::process_mouse_moved_event(e);
            m_control.notify_mouse_moved_event(e);
        }

        auto get_control_by_position(const draw::point& point) const ->
            core::constOptionalReference<control> override
        {
            return m_control.get_control_by_position(point);
        }

    private:
        void load_window_defaults()
        {

        }

        void update_theme()
        {
            load_window_defaults();
            load_defaults();

            m_control.load_defaults();
            m_control.invalidate();
        }


        void init_main_window_visibility()
        {
            addVisibleChangedListener(
                [this](auto& e)
                {
                    if (e.get_new_value())
                    {
                        m_impl.show();
                    }
                    else
                    {
                        m_impl.hide();
                    }
                });
        }

        void init_size()
        {
            //auto& dimension = ui_manager::get_instance().getDefault(
            //                "main_window", "size", dimension{300, 200});
            //ETOTODO: MOVE THIS TO THE THEME

            m_control.setActualSize(draw::dimension{800, 600});

            addSizeChangedListener([this](auto& e)
            {
                auto& new_value = e.get_new_value();

                setActualSize(new_value);
                m_control.setActualSize(new_value);
                m_control.invalidate();
            });

            addActualSizeChangedListener([this](auto& e)
            {
                auto& newValue = e.get_new_value();
                m_control.setActualSize(newValue);
                m_control.invalidate();
            });
        }
    };
}