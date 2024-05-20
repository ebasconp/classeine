#pragma once

#include "ControlBase.h"

namespace clsn::ui
{
    template <typename Model, typename Renderer, typename Controller>
    class Control final : public ControlBase
    {
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

            setFont(uiManager.getDefault(sectionName, "font", Font{}));

            initEvents();
        }


        std::string_view getDefaultSectionName() const
        {
            return m_controller.getDefaultSectionName();
        }

        Model& getModel() noexcept { return m_model; }
        const Model& getModel() const noexcept { return m_model; }


        void paint(Graphics& graphics, const Region& region) override
        {
            m_renderer.paint(graphics, region, *this);
        }

        Controller& getController() { return m_controller; }
        const Controller& getController() const { return m_controller; }

    private:
        void initEvents()
        {
            m_controller.initEvents(*this);
        }
    };
}