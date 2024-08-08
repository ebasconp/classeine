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
        control_optional_reference m_mouse_grabber_control;
        const_control_optional_reference m_hovered_control;

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
                            const_control_optional_reference = 0;

    protected:
        void process_mouse_moved_event(events::MouseMovedEvent &e) override;

    private:
        void init_defaults();
        void init_visibility();
    };
}