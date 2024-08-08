#include "control.h"
#include "UIManager.h"
#include "window.h"

#include "clsn/draw/region.h"

#include <iostream> //ETOTODO REMOVE THIS

namespace clsn::ui
{
    using clsn::ui::renderers::NullRenderer;

    control::control(std::string_view section_name)
    : m_defaultSectionName{section_name}
    , m_invalidated{true}
    {
        init_events();
    }

    void control::paint(graphics& graphics, const region& region) const
    {
        debug_count("paint");

        get_renderer().paint(graphics, region, *this);
    }

    void control::notify_mouse_click_event(MouseClickEvent& e)
    {
        process_mouse_click_event(e);
    }

    void control::add_mouse_moved_listener(event_listener<MouseMovedEvent> event)
    {
        m_mouse_moved_listeners.add(std::move(event));
    }

    void control::notify_mouse_moved_event(MouseMovedEvent& e)
    {
        process_mouse_moved_event(e);
    }

    void control::process_mouse_click_event(events::MouseClickEvent& e)
    {
        if (!is_enabled())
            return;

        if (e.getStatus() == MouseClickStatus::released)
        {
            invoke_in_parent_window([](auto& w) { w.release_mouse(); });
        }

        m_mouse_click_listeners.notify(e);
    }

    void control::process_mouse_moved_event(events::MouseMovedEvent& e)
    {
        if (!is_enabled())
            return;

        m_mouse_moved_listeners.notify(e);
    }

    void control::add_mouse_click_listener(event_listener<MouseClickEvent> event)
    {
        m_mouse_click_listeners.add(std::move(event));
    }

    auto control::get_default_section_name() const -> std::string_view
    {
        return m_defaultSectionName;
    }

    void control::set_renderer(const std::shared_ptr<IRenderer>& renderer)
    {
        m_renderer = renderer;
    }

    void control::do_layout()
    {
        debug_count("do_layout");
    }

    void control::invalidate() const noexcept { m_invalidated = true; }

    void control::validate() const noexcept { m_invalidated = false; }

    auto control::is_invalidated() const noexcept -> bool
    {
        return m_invalidated;
    }

    void control::release_mouse()
    {
        // Nothing to do here
    }

    auto control::operator==(const control& other) const -> bool
    {
        return this == &other;
    }


    auto control::operator!=(const control& other) const -> bool
    {
        return this != &other;
    }


    void control::init_events()
    {
        add_visible_changed_listener([this](auto&) { invalidate(); });
    }

    void control::set_parent_window(
        std::optional<std::reference_wrapper<window>> parentWindow)
    {
        m_parentWindow = parentWindow;
    }

    std::optional<std::reference_wrapper<window>> control::get_parent_window()
    {
        return m_parentWindow;
    }

    std::optional<std::reference_wrapper<const window>>
        control::get_parent_window() const
    {
        return m_parentWindow;
    }

    auto control::contains_point(const point& point) const -> bool
    {
        return region{m_actual_position.get(), m_actual_size.get()}.contains_point(point);
    }

    auto control::get_control_by_position(const point& point) const
        -> std::optional<std::reference_wrapper<const control>>
    {
        if (this->contains_point(point))
            return *this;

        return std::nullopt;
    }

    auto control::is_hovered() const -> bool
    {
        if (!m_parentWindow.has_value())
            return false;

        return m_parentWindow.value().get().is_hovered(*this);
    }


    auto control::get_renderer() -> IRenderer&
    {
        if (m_renderer == nullptr)
            m_renderer = UIManager::getInstance().getRendererByControl(*this);

        return *m_renderer.get();
    }

    auto control::get_renderer() const -> const IRenderer&
    {
        if (m_renderer == nullptr)
            m_renderer = UIManager::getInstance().getRendererByControl(*this);

        return *m_renderer.get();
    }

    void control::load_defaults()
    {
        // Do nothing here
    }

    auto control::get_actual_background_color() const -> const color&
    {
        const auto& color = get_background_color();
        if (color.has_value())
            return color.value();

        return UIManager::getInstance().getColor(
                    m_defaultSectionName, "controlBackgroundColor");
    }

    auto control::get_actual_foreground_color() const -> const color&
    {
        const auto& color = get_foreground_color();
        if (color.has_value())
            return color.value();

        return UIManager::getInstance().getColor(
                    m_defaultSectionName, "controlForegroundColor");
    }

    auto control::get_actual_font() const -> const font&
    {
        const auto& font = get_font();
        if (font.has_value())
            return font.value();

        return UIManager::getInstance().get_font(m_defaultSectionName, "defaultFont");
    }

    auto control::get_actual_preferred_size() const -> const dimension&
    {
        const auto& size = get_preferred_size();
        if (size.has_value())
            return size.value();

        return UIManager::getInstance().getDimension(m_defaultSectionName, "preferredSize");
    }

}