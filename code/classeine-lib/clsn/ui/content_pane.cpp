#include <clsn/ui/content_pane.h>

#include <clsn/ui/renderers/content_pane_renderer.h>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    content_pane::content_pane(std::string_view sectionName)
    : paintable_control{sectionName}
    {
        init_content_pane_events();
    }

    void content_pane::init_content_pane_events()
    {
        addActualSizeChangedListener([this](auto& )
        {
            do_layout();
        });
    }

    void content_pane::do_layout()
    {
        auto control_optional_ref = get_actual_inner_control();
        if (!control_optional_ref.hasValue())
            return;

        auto& inner_control_value = control_optional_ref.getRef();
        inner_control_value.setActualPosition(this->getActualPosition());
        inner_control_value.setActualSize(this->getActualSize());
        inner_control_value.do_layout();
    }

    auto content_pane::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::content_pane_renderer>();
    }

    void content_pane::invalidate() const noexcept
    {
        control::invalidate();

        if (get_actual_inner_control().hasValue())
            get_actual_inner_control().getRef().invalidate();
    }

    void content_pane::validate() const noexcept
    {
        control::validate();

        if (get_actual_inner_control().hasValue())
            get_actual_inner_control().getRef().validate();
    }

    auto content_pane::is_invalidated() const noexcept -> bool
    {
        if (!get_actual_inner_control().hasValue())
        {
            return control::is_invalidated();
        }

        return get_actual_inner_control().getRef().is_invalidated();
    }

    void content_pane::process_mouse_click_event(events::mouse_click_event& e)
    {
        auto control_optional_ref = get_actual_inner_control();
        if (!control_optional_ref.hasValue())
            return;

        auto& inner_control = control_optional_ref.getRef();
        if (!inner_control.isVisible() || !inner_control.isEnabled())
            return;

        if (inner_control.containsPoint(e.get_point()))
        {
            inner_control.notify_mouse_click_event(e);
        }

        control::process_mouse_click_event(e);
    }

    void content_pane::process_mouse_moved_event(events::mouse_moved_event& e)
    {
        control::process_mouse_moved_event(e);

        auto control_optional_ref = get_actual_inner_control();
        if (!control_optional_ref.hasValue())
            return;

        auto& inner_control = control_optional_ref.getRef();
        if (!inner_control.isVisible() || !inner_control.isEnabled())
            return;

        if (inner_control.containsPoint(e.getPosition()))
        {
            inner_control.notify_mouse_moved_event(e);
        }
    }

    auto content_pane::get_control_by_position(const Point &Point) const
            -> constOptionalReference<control>
    {
        auto control_optional_ref = get_actual_inner_control();

        if (!control_optional_ref.hasValue())
            return {};

        auto& inner_control = control_optional_ref.getRef();
        if (!inner_control.isVisible() || !inner_control.isEnabled())
            return {};

        return inner_control.get_control_by_position(Point);
    }
}