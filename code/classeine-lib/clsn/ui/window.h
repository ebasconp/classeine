#pragma once

#include "control.h"

#include "clsn/core/property.h"

#include "clsn/draw/dimension.h"
#include "clsn/draw/point.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    class window : public control
    {
        optional_reference<control> m_mouse_grabber_control;
        const_optional_reference<control> m_hovered_control;

    public:
        explicit window(std::string_view section_name);

        CLSN_PROPERTY(position, point, true)
        CLSN_PROPERTY(minimum_size, dimension, true)
        CLSN_PROPERTY(size, dimension, true)
        CLSN_BOOL_PROPERTY_VAL(resizable, true, true);

        void grabMouse(control& control);
        void release_mouse();

        auto is_hovered(const control& control) const -> bool;

        virtual auto get_control_by_position(const point& point) const ->
                            const_optional_reference<control> = 0;

    protected:
        void process_mouse_moved_event(events::mouse_moved_event &e) override;

    private:
        void init_defaults();
        void init_visibility();
    };
}