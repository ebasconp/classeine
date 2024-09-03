#pragma once

#include "control.h"
#include "ui_manager.h"

#include "window.h"


namespace clsn::ui
{
    template <typename ElementType>
    class container : public control
    {
        mutable bool m_needs_to_paint_the_container;

    public:
        explicit container(std::string_view section_name)
        : control{section_name}
        , m_needs_to_paint_the_container{false}
        {
            load_container_defaults();
            init_container_events();
        }

        CLSN_PROPERTY_VAL(margin, int, true, 0)

        virtual void iterate_elements(std::function<void(ElementType&)> func) = 0;
        virtual void iterate_elements(std::function<void(const ElementType&)> func)  const = 0;

        virtual void iterate_controls(std::function<void(control&)> func) = 0;
        virtual void iterate_controls(std::function<void(const control&)> func) const = 0;

        virtual auto get_count() const noexcept -> int = 0;

        virtual auto get_element_at(int index) -> ElementType& = 0;
        virtual auto get_element_at(int index) const -> const ElementType& = 0;

        virtual auto operator[](int index) noexcept -> control& = 0;
        virtual auto operator[](int index) const noexcept -> const control& = 0;

        auto is_empty() const -> bool
        {
            return get_count() == 0;
        }

        void invalidate() const noexcept override
        {
            m_needs_to_paint_the_container = true;

            iterate_controls([](auto& c) { c.invalidate(); });
        }

        void validate() const noexcept override
        {
            m_needs_to_paint_the_container = false;

            iterate_controls([](auto& c) { c.validate(); });
        }

        auto needs_to_paint_the_container() const noexcept -> bool
        {
            return m_needs_to_paint_the_container;
        }

        auto is_invalidated() const noexcept -> bool override
        {
            if (m_needs_to_paint_the_container && is_empty())
                return true;

            auto invalidated = false;

            iterate_controls([&invalidated](auto& c)
            {
               if (!invalidated && c.is_invalidated())
                   invalidated = true;
            });

            return invalidated;
        }

        auto get_visible_count() const -> int
        {
            auto count = 0;

            iterate_controls([&count](auto& c) { if (c.is_visible()) count++; });

            return count;
        }

        void load_defaults() override
        {
            control::load_defaults();

            load_container_defaults();

            iterate_controls([](control& c) { c.load_defaults(); });
        }

        auto get_control_by_position(const point &point) const
    -> std::optional<std::reference_wrapper<const control>> override
        {
            std::optional<std::reference_wrapper<const control>> result;

            iterate_controls([&](const control& ctrl)
            {
                 if (result.has_value())
                     return;

                 if (!ctrl.is_visible() || !ctrl.is_enabled())
                     return;

                 result = ctrl.get_control_by_position(point);
            });

            return result;
        }

    protected:
        void init_new_control(control& control)
        {
            control.set_parent_window(get_parent_window());
            control.set_parent_control(*this);

            control.add_visible_changed_listener(
                [this](auto&)
                {
                    do_layout();
                    invalidate();
                });
        }

        void process_mouse_click_event(events::mouse_click_event& e) override
        {
            iterate_controls([&](control& ctrl)
            {
                if (!ctrl.is_visible() || !ctrl.is_enabled())
                    return;

                if (ctrl.contains_point(e.getPoint()))
                {
                    ctrl.notify_mouse_click_event(e);
                }
            });

            control::process_mouse_click_event(e);
        }

        void process_mouse_moved_event(events::mouse_moved_event& e) override
        {
            control::process_mouse_moved_event(e);

            iterate_controls([&](control& ctrl)
            {
                if (!ctrl.is_visible() || !ctrl.is_enabled())
                    return;

                if (ctrl.contains_point(e.position))
                {
                    ctrl.notify_mouse_moved_event(e);
                }
            });
        }

    private:
        void init_container_events()
        {
            add_enabled_changed_listener([this](auto& e)
            {
                iterate_controls([&](control& c)
                {
                    c.set_enabled(e.get_new_value());
                });
            });

            add_actual_size_changed_listener(
                [this](auto& )
                {
                    do_layout();
                });
        }

        void load_container_defaults()
        {
            auto& uiManager = clsn::ui::ui_manager::get_instance();
            auto section_name = get_default_section_name();

            set_background_color(uiManager.get_color(
                section_name, "container_background_color"));

            set_foreground_color(uiManager.get_color(
                section_name, "container_foreground_color"));
        }
    };
}
