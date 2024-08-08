#include "window.h"

#include "ui_manager.h"

#include <iostream> //ETOTODO: REMOVE THIS

namespace
{
    using namespace clsn::ui;

    auto areEqual(
            const const_control_optional_reference& a,
            const const_control_optional_reference& b) -> bool
    {
        if (a.has_value() != b.has_value())
            return false;

        if (!a.has_value())
            return true;

        return a.value().get() == b.value().get();
    }
}
namespace clsn::ui
{
    window::window(std::string_view section_name)
    : control(section_name)
    {
        init_visibility();
        init_defaults();
    }

    void window::init_defaults()
    {
        //ETOTODO: MOVE THIS TO THE tHEME
/*        setMinimumSize(ui_manager::get_instance().getDefault(
            get_default_section_name(), "minimumSize", dimension{50, 50}));

        auto& dimension = ui_manager::get_instance().getDefault(
            get_default_section_name(), "size", dimension{300, 200});

        set_actual_size(dimension);*/

        set_minimum_size({50, 50});
        set_actual_position({300, 200});
    }

    void window::init_visibility()
    {
        set_visible(false);
    }

    void window::grabMouse(control& control)
    {
        m_mouse_grabber_control = std::ref(control);
    }

    void window::release_mouse()
    {
        if (m_mouse_grabber_control.has_value())
        {
            m_mouse_grabber_control.value().get().release_mouse();
            m_mouse_grabber_control = std::nullopt;
        }
    }

    void window::process_mouse_moved_event(events::MouseMovedEvent &e)
    {
        auto currentlyHovered = get_control_by_position(e.position);
        if (!areEqual(m_hovered_control, currentlyHovered))
        {
            if (m_hovered_control.has_value())
            {
                m_hovered_control.value().get().invalidate();
            }

            m_hovered_control = currentlyHovered;

            if (m_hovered_control.has_value())
            {
                m_hovered_control.value().get().invalidate();
            }

        }
    }

    auto window::is_hovered(const control& control) const -> bool
    {
        if (!m_hovered_control.has_value())
            return false;

        return control == m_hovered_control.value().get();
    }

}