#pragma once

#include "clsn/ui/Graphics.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Dimension.h"

#include "clsn/core/Property.h"

namespace clsn::ui
{
    using namespace clsn::draw;


    template <typename Model, typename EventManager, typename Renderer>
    class Control
    {
        CLSN_PROPERTY_VAL(Dimension, true, Size, (Dimension{600, 400}));
        CLSN_PROPERTY_VAL(bool, true, Visible, true);
        CLSN_PROPERTY(Color, true, BackgroundColor);
        CLSN_PROPERTY(Color, true, ForegroundColor);

        Model m_model;
        EventManager m_eventManager;
        Renderer m_renderer;

    public:
        Control() = default;

        void paint(Graphics& graphics)
        {
            m_renderer.paint(graphics, *this);
        }

        EventManager& getEventManager() { return m_eventManager; }
        const EventManager& getEventManager() const { return m_eventManager; }
    };
}