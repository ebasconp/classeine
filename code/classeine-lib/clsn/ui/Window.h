#pragma once

#include "Control.h"

#include "clsn/core/property.h"

#include "clsn/draw/dimension.h"
#include "clsn/draw/point.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    class Window : public Control
    {
        ControlOptionalReference m_mouseGrabberControl;
        ConstControlOptionalReference m_hoveredControl;

    public:
        explicit Window(std::string_view section_name);

        CLSN_PROPERTY(position, point, true)
        CLSN_PROPERTY(minimum_size, dimension, true)
        CLSN_PROPERTY(size, dimension, true)
        CLSN_BOOL_PROPERTY_VAL(resizable, true, true);

        void grabMouse(Control& control);
        void releaseMouse();

        auto isHovered(const Control& control) const -> bool;

        virtual auto getControlByPosition(const point& point) const ->
                            ConstControlOptionalReference = 0;

    protected:
        void processMouseMovedEvent(events::MouseMovedEvent &e) override;

    private:
        void initDefaults();
        void initVisibility();
    };
}