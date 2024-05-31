#include "Control.h"

#include "clsn/ui/renderers/NullRenderer.h"

namespace clsn::ui
{
    using clsn::ui::renderers::NullRenderer;

    Control::Control(std::string_view sectionName)
    : m_defaultSectionName{sectionName}
    , m_invalidated{true}
    {
        auto& uiManager = UIManager::getInstance();

        m_renderer = uiManager.getDefault<std::shared_ptr<IRenderer>>(
            sectionName, "renderer", std::make_shared<NullRenderer>());

        setBackgroundColor(
            uiManager.getDefault(sectionName, "backgroundColor", Colors::RED));

        setForegroundColor(uiManager.getDefault(
            sectionName, "foregroundColor", Colors::WHITE));

        setFont(uiManager.getDefault(sectionName, "font", Font{}));

        initEvents();
    }

    void Control::paint(Graphics& graphics, const Region& region) const
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

    auto Control::getDefaultSectionName() const -> std::string_view
    {
        return m_defaultSectionName;
    }

    void Control::setRenderer(const std::shared_ptr<IRenderer>& renderer)
    {
        m_renderer = renderer;
    }

    void Control::invalidate() const noexcept { m_invalidated = true; }

    void Control::validate() const noexcept { m_invalidated = false; }

    auto Control::isInvalidated() const noexcept -> bool
    {
        return m_invalidated;
    }


    void Control::initEvents()
    {
        addVisibleChangedListener([this](auto&)
        {
            invalidate();
        });
    }
}