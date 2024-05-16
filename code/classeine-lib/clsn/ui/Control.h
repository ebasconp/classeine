#pragma once

#include "clsn/ui/Graphics.h"
#include "clsn/ui/UIManager.h"

#include "clsn/draw/Color.h"
#include "clsn/draw/Colors.h"
#include "clsn/draw/Dimension.h"
#include "clsn/draw/Region.h"

#include "clsn/core/Property.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    template <typename Model, typename Renderer, typename Controller>
    class Control
    {
        CLSN_PROPERTY_VAL(Dimension, true, Size, (Dimension{600, 400}));
        CLSN_PROPERTY_VAL(bool, true, Visible, true);
        CLSN_PROPERTY(Color, true, BackgroundColor);
        CLSN_PROPERTY(Color, true, ForegroundColor);

        Model m_model;
        Renderer m_renderer;
        Controller m_controller;

    public:
        Control()
        {
            auto& uiManager = UIManager::getInstance();

            auto sectionName = getDefaultSectionName();

            setBackgroundColor(uiManager.getDefault(
                sectionName, "backgroundColor", Colors::RED));

            setForegroundColor(uiManager.getDefault(
                sectionName, "foregroundColor", Colors::WHITE));
        }


        std::string_view getDefaultSectionName() const
        {
            return m_controller.getDefaultSectionName();
        }

        void paint(Graphics& graphics, const Region& region)
        {
            m_renderer.paint(graphics, region, *this);
        }

        Controller& getController() { return m_controller; }
        const Controller& getController() const { return m_controller; }
    };
}