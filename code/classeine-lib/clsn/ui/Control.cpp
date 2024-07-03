#include "Control.h"
#include "Window.h"

#include "clsn/draw/Colors.h"

#include "clsn/ui/renderers/NullRenderer.h"

namespace clsn::ui
{
    using clsn::ui::renderers::NullRenderer;

    Control::Control(std::string_view sectionName)
    : m_defaultSectionName{sectionName}
    , m_invalidated{true}
    {
        auto& uiManager = UIManager::getInstance();

        m_renderer =
            uiManager
                .getDefault<LazyRenderer>(
                    sectionName, "renderer", makeLazyRenderer<NullRenderer>())
                .get();

        setBackgroundColor(
            uiManager.getDefault(sectionName, "backgroundColor", Colors::RED));

        setForegroundColor(uiManager.getDefault(
            sectionName, "foregroundColor", Colors::WHITE));

        setFont(uiManager.getDefault(sectionName, "font", Font{}));

        initEvents();
    }

    void Control::paint(Graphics& graphics, const Region& region) const
    {
        debug_count("paint");
        m_renderer->paint(graphics, region, *this);
    }

    void Control::notifyMouseClickEvent(MouseClickEvent& e)
    {
        processMouseClickEvent(e);
    }

    void Control::processMouseClickEvent(events::MouseClickEvent& e)
    {
        if (e.getStatus() == MouseClickStatus::released)
        {
            invokeInParentWindow([](auto& w) { w.releaseMouse(); });
        }

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

    void Control::doLayout() noexcept
    {
        debug_count("doLayout");
        m_renderer->doLayout(*this);
    }

    void Control::invalidate() const noexcept { m_invalidated = true; }

    void Control::validate() const noexcept { m_invalidated = false; }

    auto Control::isInvalidated() const noexcept -> bool
    {
        return m_invalidated;
    }

    void Control::releaseMouse()
    {
        // Nothing to do here
    }

    void Control::initEvents()
    {
        addVisibleChangedListener([this](auto&) { invalidate(); });
    }

    void Control::setParentWindow(
        std::optional<std::reference_wrapper<Window>> parentWindow)
    {
        m_parentWindow = parentWindow;
    }

    std::optional<std::reference_wrapper<Window>> Control::getParentWindow()
    {
        return m_parentWindow;
    }

    std::optional<std::reference_wrapper<const Window>>
        Control::getParentWindow() const
    {
        return m_parentWindow;
    }

    auto Control::containsPoint(const Point& point) const -> bool
    {
        return Region{m_ActualPosition.get(), m_ActualSize.get()}.containsPoint(point);
    }
}