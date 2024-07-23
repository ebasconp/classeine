#pragma once

#include "Control.h"

#include "clsn/core/Property.h"

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
        explicit Window(std::string_view sectionName);

        CLSN_PROPERTY(Position, Point, true)
        CLSN_PROPERTY(MinimumSize, Dimension, true)
        CLSN_PROPERTY(Size, Dimension, true)
        CLSN_BOOL_PROPERTY_VAL(Resizable, true, true);

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