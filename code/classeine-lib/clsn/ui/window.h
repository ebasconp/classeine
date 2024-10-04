// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/captionable_control.h>

#include <clsn/draw/forward.h>

#include <clsn/core/property.h>


namespace clsn::ui
{
    class window : public captionable_control
    {
        core::optional_reference<control> m_mouse_grabber_control;
        core::const_optional_reference<control> m_hovered_control;

    public:
        explicit window(std::string_view section_name);

        CLSN_HEADER_PROPERTY(position, clsn::draw::point, true)
        CLSN_HEADER_PROPERTY(minimum_size, clsn::draw::dimension, true)
        CLSN_HEADER_PROPERTY(size, clsn::draw::dimension, true)
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(resizable, true, true)

        void grab_mouse(control& control);
        void release_mouse();

        auto is_hovered(const control& control) const -> bool;

        virtual auto get_control_by_position(const clsn::draw::point& point) const ->
                            core::const_optional_reference<control> = 0;

    protected:
        void process_mouse_moved_event(events::mouse_moved_event &e) override;

    private:
        void init_defaults();
        void init_visibility();
    };
}