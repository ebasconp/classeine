#include "Control.h"
#include "UIManager.h"
#include "Window.h"

#include "clsn/draw/Region.h"

#include <iostream> //ETOTODO REMOVE THIS

namespace clsn::ui
{
    using clsn::ui::renderers::NullRenderer;

    Control::Control(std::string_view sectionName)
    : m_defaultSectionName{sectionName}
    , m_invalidated{true}
    {
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

    void Control::addMouseMovedListener(EventListener<MouseMovedEvent> event)
    {
        m_mouseMovedListeners.add(std::move(event));
    }

    void Control::notifyMouseMovedEvent(MouseMovedEvent& e)
    {
        processMouseMovedEvent(e);
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

    void Control::processMouseMovedEvent(events::MouseMovedEvent& e)
    {
        if (!isEnabled())
            return;

        m_mouseMovedListeners.notify(e);
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

    auto Control::operator==(const Control& other) const -> bool
    {
        return this == &other;
    }


    auto Control::operator!=(const Control& other) const -> bool
    {
        return this != &other;
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

    auto Control::getControlByPosition(const Point& point) const
        -> std::optional<std::reference_wrapper<const Control>>
    {
        if (this->containsPoint(point))
            return *this;

        return std::nullopt;
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

    void Control::loadDefaults()
    {
        // Do nothing here
    }

    auto Control::getActualBackgroundColor() const -> const Color&
    {
        const auto& color = getBackgroundColor();
        if (color.has_value())
            return color.value();

        return UIManager::getInstance().getColor(
                    m_defaultSectionName, "controlBackgroundColor");
    }

    auto Control::getActualForegroundColor() const -> const Color&
    {
        const auto& color = getForegroundColor();
        if (color.has_value())
            return color.value();

        return UIManager::getInstance().getColor(
                    m_defaultSectionName, "controlForegroundColor");
    }

    auto Control::getActualFont() const -> const Font&
    {
        const auto& font = getFont();
        if (font.has_value())
            return font.value();

        return UIManager::getInstance().getFont(m_defaultSectionName, "defaultFont");
    }

    auto Control::getActualPreferredSize() const -> const Dimension&
    {
        const auto& size = getPreferredSize();
        if (size.has_value())
            return size.value();

        return UIManager::getInstance().getDimension(m_defaultSectionName, "preferredSize");
    }

}