#include "Control.h"
#include "UIManager.h"
#include "Window.h"

#include "clsn/draw/Colors.h"

namespace clsn::ui
{
    using clsn::ui::renderers::NullRenderer;

    Control::Control(std::string_view sectionName)
    : m_defaultSectionName{sectionName}
    , m_invalidated{true}
    {
        auto& uiManager = UIManager::getInstance();

        setBackgroundColor(
            uiManager.getDefault(sectionName, "controlBackgroundColor", clsn::draw::Colors::makeRed()));

        setForegroundColor(uiManager.getDefault(
            sectionName, "controlForegroundColor", Colors::makeWhite()));

        setFont(uiManager.getDefault(sectionName, "font", Font{}));

        initEvents();
    }

    void Control::paint(Graphics& graphics, const Region& region) const
    {
        debug_count("paint");
        getRenderer().paint(graphics, region, *this);
    }

    void Control::notifyMouseClickEvent(MouseClickEvent& e)
    {
        processMouseClickEvent(e);
    }

    void Control::processMouseClickEvent(events::MouseClickEvent& e)
    {
        if (!isEnabled())
            return;

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
        getRenderer().doLayout(*this);
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

    auto Control::getRenderer() -> IRenderer&
    {
        if (m_renderer == nullptr)
            m_renderer = UIManager::getInstance().getRendererByControl(*this);

        return *m_renderer.get();
    }

    auto Control::getRenderer() const -> const IRenderer&
    {
        if (m_renderer == nullptr)
            m_renderer = UIManager::getInstance().getRendererByControl(*this);

        return *m_renderer.get();
    }
}