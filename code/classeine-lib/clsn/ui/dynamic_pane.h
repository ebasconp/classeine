// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "control.h"

#include "clsn/draw/forward.h"

#include <memory>

namespace clsn::ui
{
    class dynamic_pane : public control
    {
        std::shared_ptr<control> m_inner_control;

    public:
        dynamic_pane();

        void do_layout() override;

        auto get_inner_control() -> std::shared_ptr<control>&;
        auto get_inner_control() const -> const std::shared_ptr<control>&;

        void set_inner_control(const std::shared_ptr<control>& ctrl);

        void invalidate() const noexcept override;
        void validate() const noexcept override;
        auto is_invalidated() const noexcept -> bool override;

        auto get_control_by_position(const clsn::draw::point& point) const
            -> const_optional_reference<control> override;

    protected:
        void process_mouse_click_event(events::mouse_click_event& e) override;
        void process_mouse_moved_event(events::mouse_moved_event& e) override;

        auto make_default_renderer() const -> std::unique_ptr<renderer_base> override;

    private:
        void init_dynamic_pane_events();
    };
}