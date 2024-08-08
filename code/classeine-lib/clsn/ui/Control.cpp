#include "Control.h"
#include "UIManager.h"
#include "Window.h"

#include "clsn/draw/Region.h"

#include <iostream> //ETOTODO REMOVE THIS

namespace clsn::ui
{
    using clsn::ui::renderers::NullRenderer;

    Control::Control(std::string_view section_name)
    : m_defaultSectionName{section_name}
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

    void Control::addMouseMovedListener(event_listener<MouseMovedEvent> event)
    {
        m_mouseMovedListeners.add(std::move(event));
    }

    void Control::notifyMouseMovedEvent(MouseMovedEvent& e)
    {
        processMouseMovedEvent(e);
    }

    void Control::processMouseClickEvent(events::MouseClickEvent& e)
    {
        if (!is_enabled())
            return;

        if (e.getStatus() == MouseClickStatus::released)
        {
            invokeInParentWindow([](auto& w) { w.releaseMouse(); });
        }

        m_mouseClickListeners.notify(e);
    }

    void Control::processMouseMovedEvent(events::MouseMovedEvent& e)
    {
        if (!is_enabled())
            return;

        m_mouseMovedListeners.notify(e);
    }

    void Control::addMouseClickListener(event_listener<MouseClickEvent> event)
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

    void Control::doLayout()
    {
        debug_count("doLayout");
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
        add_visible_changed_listener([this](auto&) { invalidate(); });
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
        return Region{m_actual_position.get(), m_actual_size.get()}.containsPoint(point);
    }

    auto Control::getControlByPosition(const Point& point) const
        -> std::optional<std::reference_wrapper<const Control>>
    {
        if (this->containsPoint(point))
            return *this;

        return std::nullopt;
    }

    auto Control::isHovered() const -> bool
    {
        if (!m_parentWindow.has_value())
            return false;

        return m_parentWindow.value().get().isHovered(*this);
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
        const auto& color = get_background_color();
        if (color.has_value())
            return color.value();

        return UIManager::getInstance().getColor(
                    m_defaultSectionName, "controlBackgroundColor");
    }

    auto Control::getActualForegroundColor() const -> const Color&
    {
        const auto& color = get_foreground_color();
        if (color.has_value())
            return color.value();

        return UIManager::getInstance().getColor(
                    m_defaultSectionName, "controlForegroundColor");
    }

    auto Control::getActualFont() const -> const Font&
    {
        const auto& font = get_font();
        if (font.has_value())
            return font.value();

        return UIManager::getInstance().get_font(m_defaultSectionName, "defaultFont");
    }

    auto Control::getActualPreferredSize() const -> const Dimension&
    {
        const auto& size = get_preferred_size();
        if (size.has_value())
            return size.value();

        return UIManager::getInstance().getDimension(m_defaultSectionName, "preferredSize");
    }

}