#pragma once

#include "Control.h"

#include "clsn/core/property.h"

#include "clsn/draw/Dimension.h"
#include "clsn/draw/Point.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    class Window : public Control
    {
        ControlOptionalReference m_mouseGrabberControl;
        ConstControlOptionalReference m_hoveredControl;

    public:
        explicit Window(std::string_view section_name);

        CLSN_PROPERTY(position, Point, true)
        CLSN_PROPERTY(minimum_size, Dimension, true)
        CLSN_PROPERTY(size, Dimension, true)
        CLSN_BOOL_PROPERTY_VAL(resizable, true, true);

        void grabMouse(Control& control);
        void releaseMouse();

        auto isHovered(const Control& control) const -> bool;

        virtual auto getControlByPosition(const Point& point) const ->
                            ConstControlOptionalReference = 0;

    protected:
        void processMouseMovedEvent(events::MouseMovedEvent &e) override;

    private:
        void initDefaults();
        void initVisibility();
    };
}