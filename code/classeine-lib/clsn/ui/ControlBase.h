#pragma once

#include "clsn/ui/Graphics.h"
#include "clsn/ui/UIManager.h"

#include "clsn/ui/events/ControlResizedEvent.h"
#include "clsn/ui/events/MouseClickEvent.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Colors.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Region.h"

#include "clsn/core/EventListenerList.h"
#include "clsn/core/Property.h"

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;
    using namespace clsn::ui::events;

    class ControlBase
    {
        EventListenerList<MouseClickEvent> m_mouseClickListeners;
        EventListenerList<ControlResizedEvent> m_controlResizedListeners;

    public:
        virtual ~ControlBase() = default;

        CLSN_PROPERTY_VAL(Dimension, true, Size, (Dimension{600, 400}));
        CLSN_BOOL_PROPERTY_VAL(true, Visible, true);
        CLSN_PROPERTY(Color, true, BackgroundColor);
        CLSN_PROPERTY(Color, true, ForegroundColor);
        CLSN_PROPERTY(Font, true, Font);

        virtual void paint(Graphics& graphics, const Region& region) = 0;

        void processMouseClickEvent(events::MouseClickEvent& e)
        {
            m_mouseClickListeners.notify(e);
        }

        void addMouseClickListener(EventListener<MouseClickEvent> event)
        {
            m_mouseClickListeners.add(std::move(event));
        }
    };
}