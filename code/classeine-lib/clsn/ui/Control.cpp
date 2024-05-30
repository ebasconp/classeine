#include "Control.h"

#include "clsn/ui/renderers/NullRenderer.h"

namespace clsn::ui
{
    Control::Control(std::string_view sectionName)
    : m_defaultSectionName{sectionName}
    {
        auto& uiManager = UIManager::getInstance();

        m_renderer = uiManager.getDefault<std::shared_ptr<IRenderer>>(
            sectionName, "renderer", std::make_shared<NullRenderer>());

        setBackgroundColor(
            uiManager.getDefault(sectionName, "backgroundColor", Colors::RED));

        setForegroundColor(uiManager.getDefault(
            sectionName, "foregroundColor", Colors::WHITE));

        setFont(uiManager.getDefault(sectionName, "font", Font{}));
    }

    void Control::paint(Graphics& graphics, const Region& region)
    {
        m_renderer->paint(graphics, region, *this);
    }

    void Control::processMouseClickEvent(events::MouseClickEvent& e)
    {
        m_mouseClickListeners.notify(e);
    }

    void Control::addMouseClickListener(EventListener<MouseClickEvent> event)
    {
        m_mouseClickListeners.add(std::move(event));
    }

    std::string_view Control::getDefaultSectionName() const
    {
        return m_defaultSectionName;
    }

    void Control::setRenderer(const std::shared_ptr<IRenderer>& renderer)
    {
        m_renderer = renderer;
    }
}