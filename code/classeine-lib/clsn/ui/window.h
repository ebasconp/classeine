// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/captionable_control.h>

#include <clsn/draw/forward.h>

#include <clsn/core/Property.h>


namespace clsn::ui
{
    class window : public captionable_control
    {
        core::OptionalReference<control> m_mouse_grabber_control;
        core::constOptionalReference<control> m_hovered_control;

    public:
        explicit window(std::string_view sectionName);

        CLSN_HEADER_PROPERTY(Position, clsn::draw::point, true)
        CLSN_HEADER_PROPERTY(MinimumSize, clsn::draw::dimension, true)
        CLSN_HEADER_PROPERTY(Size, clsn::draw::dimension, true)
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Resizable, true, true)

        void grab_mouse(control& control);
        void release_mouse();

        auto is_hovered(const control& control) const -> bool;

        virtual auto get_control_by_position(const clsn::draw::point& point) const ->
                            core::constOptionalReference<control> = 0;

    protected:
        void process_mouse_moved_event(events::mouse_moved_event &e) override;

    private:
        void init_defaults();
        void init_visibility();
    };
}