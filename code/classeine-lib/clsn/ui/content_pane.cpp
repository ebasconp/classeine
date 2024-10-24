#include <clsn/ui/content_pane.h>

#include <clsn/ui/renderers/content_pane_renderer.h>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    content_pane::content_pane(std::string_view section_name)
    : paintable_control{section_name}
    {
        init_content_pane_events();
    }

    void content_pane::init_content_pane_events()
    {
        add_actual_size_changed_listener([this](auto& )
        {
            do_layout();
        });
    }

    void content_pane::do_layout()
    {
        auto control_optional_ref = get_actual_inner_control();
        if (!control_optional_ref.has_value())
            return;

        auto& inner_control_value = control_optional_ref.get_ref();
        inner_control_value.set_actual_position(this->get_actual_position());
        inner_control_value.set_actual_size(this->get_actual_size());
        inner_control_value.do_layout();
    }

    auto content_pane::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::content_pane_renderer>();
    }

    void content_pane::invalidate() const noexcept
    {
        control::invalidate();

        if (get_actual_inner_control().has_value())
            get_actual_inner_control().get_ref().invalidate();
    }

    void content_pane::validate() const noexcept
    {
        control::validate();

        if (get_actual_inner_control().has_value())
            get_actual_inner_control().get_ref().validate();
    }

    auto content_pane::is_invalidated() const noexcept -> bool
    {
        if (!get_actual_inner_control().has_value())
        {
            return control::is_invalidated();
        }

        return get_actual_inner_control().get_ref().is_invalidated();
    }

    void content_pane::process_mouse_click_event(events::mouse_click_event& e)
    {
        auto control_optional_ref = get_actual_inner_control();
        if (!control_optional_ref.has_value())
            return;

        auto& inner_control = control_optional_ref.get_ref();
        if (!inner_control.is_visible() || !inner_control.is_enabled())
            return;

        if (inner_control.contains_point(e.get_point()))
        {
            inner_control.notify_mouse_click_event(e);
        }

        control::process_mouse_click_event(e);
    }

    void content_pane::process_mouse_moved_event(events::mouse_moved_event& e)
    {
        control::process_mouse_moved_event(e);

        auto control_optional_ref = get_actual_inner_control();
        if (!control_optional_ref.has_value())
            return;

        auto& inner_control = control_optional_ref.get_ref();
        if (!inner_control.is_visible() || !inner_control.is_enabled())
            return;

        if (inner_control.contains_point(e.get_position()))
        {
            inner_control.notify_mouse_moved_event(e);
        }
    }

    auto content_pane::get_control_by_position(const point &point) const
            -> const_optional_reference<control>
    {
        auto control_optional_ref = get_actual_inner_control();

        if (!control_optional_ref.has_value())
            return {};

        auto& inner_control = control_optional_ref.get_ref();
        if (!inner_control.is_visible() || !inner_control.is_enabled())
            return {};

        return inner_control.get_control_by_position(point);
    }

    void content_pane::set_parent_control(core::optional_reference<control> ctrl)
    {
        paintable_control::set_parent_control(ctrl);

        get_actual_inner_control().safe_invoke([&](auto& c)
        {
            c.set_parent_control(*this);
        });
    }

    void content_pane::set_parent_window(core::optional_reference<window> wnd)
    {
        paintable_control::set_parent_window(wnd);

        get_actual_inner_control().safe_invoke([&](auto& c)
        {
            c.set_parent_window(wnd);
        });
    }
}