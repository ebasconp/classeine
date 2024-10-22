// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/CaptionableControl.h>

#include <clsn/draw/Forward.h>

#include <clsn/core/Property.h>


namespace clsn::ui
{
    class Window : public CaptionableControl
    {
        core::OptionalReference<Control> m_mouseGrabberControl;
        core::constOptionalReference<Control> m_hoveredControl;

    public:
        explicit Window(std::string_view sectionName);

        CLSN_HEADER_PROPERTY(Position, clsn::draw::Point, true)
        CLSN_HEADER_PROPERTY(MinimumSize, clsn::draw::Dimension, true)
        CLSN_HEADER_PROPERTY(Size, clsn::draw::Dimension, true)
        CLSN_HEADER_BOOL_PROPERTY_WITH_DEFAULT_VALUE(Resizable, true, true)

        void grabMouse(Control& Control);
        void releaseMouse();

        auto isHovered(const Control& Control) const -> bool;

        virtual auto getControlByPosition(const clsn::draw::Point& Point) const ->
                            core::constOptionalReference<Control> = 0;

    protected:
        void processMouseMovedEvent(events::MouseMovedEvent &e) override;

    private:
        void initWindowDefaults();
        void initWindowVisibility();
    };
}