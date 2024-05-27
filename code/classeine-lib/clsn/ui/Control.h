#pragma once

#include "ControlBase.h"

namespace clsn::ui
{
    template <typename Model, typename Renderer, typename Controller>
    class Control : public ControlBase
    {
        Model m_model;
        Renderer m_renderer;
        Controller m_controller;

    public:
        Control(Model model =  {}, Renderer renderer = {}, Controller controller = {})
        : ControlBase(getDefaultSectionName())
        , m_model{model}
        , m_renderer{renderer}
        , m_controller{controller}
        {
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