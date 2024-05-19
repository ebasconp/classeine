#pragma once

#include "clsn/ui/Graphics.h"
#include "clsn/ui/UIManager.h"

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

    template <typename Model, typename Renderer, typename Controller>
    class Control
    {
        CLSN_PROPERTY_VAL(Dimension, true, Size, (Dimension{600, 400}));
        CLSN_BOOL_PROPERTY_VAL(true, Visible, true);
        CLSN_PROPERTY(Color, true, BackgroundColor);
        CLSN_PROPERTY(Color, true, ForegroundColor);
        CLSN_PROPERTY(Font, true, Font);

        Model m_model;
        Renderer m_renderer;
        Controller m_controller;

        EventListenerList<MouseClickEvent> m_mouseClickListeners;

    public:
        Control()
        {
            auto& uiManager = UIManager::getInstance();

            auto sectionName = getDefaultSectionName();

            setBackgroundColor(uiManager.getDefault(
                sectionName, "backgroundColor", Colors::RED));

            setForegroundColor(uiManager.getDefault(
                sectionName, "foregroundColor", Colors::WHITE));

            setFont(uiManager.getDefault(sectionName, "font", Font{}));

            initEvents();
        }


        std::string_view getDefaultSectionName() const
        {
            return m_controller.getDefaultSectionName();
        }

        Model& getModel() noexcept { return m_model; }
        const Model& getModel() const noexcept { return m_model; }


        void paint(Graphics& graphics, const Region& region)
        {
            m_renderer.paint(graphics, region, *this);
        }

        Controller& getController() { return m_controller; }
        const Controller& getController() const { return m_controller; }

        void processMouseClickEvent(events::MouseClickEvent& e)
        {
            m_mouseClickListeners.notify(e);
        }

        void addMouseClickListener(EventListener<MouseClickEvent> event)
        {
            m_mouseClickListeners.add(std::move(event));
        }

    private:
        void initEvents()
        {
            m_controller.initEvents(*this);
        }
    };
}