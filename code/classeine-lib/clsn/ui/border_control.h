#pragma once

#include "control.h"

#include "renderers/border_control_renderer.h"

namespace clsn::ui
{
    using namespace clsn::ui::renderers;

    template <typename InnerControlType>
    class border_control : public control
    {
        InnerControlType m_inner_control;

        CLSN_PROPERTY_VAL(size, int, true, 4)

    public:
        border_control() : control("border_control")
        {
            auto renderer = std::make_shared<border_control_renderer<InnerControlType>>();
            set_renderer(renderer);
        }

        void set_parent_window(std::optional<std::reference_wrapper<window>> pw) override
        {
            control::set_parent_window(pw);
            m_inner_control.set_parent_window(pw);
        }

        auto get() -> InnerControlType& { return m_inner_control; }
        auto get() const -> const InnerControlType& { return m_inner_control; }

        void process_mouse_click_event(events::mouse_click_event& e) override
        {
            console::debug("Point: [{}]; InnerControl: [POS: {} SIZE: {}]",
                e.getPoint(),
                m_inner_control.get_actual_position(),
                m_inner_control.get_actual_size());

            if (!m_inner_control.is_visible() || !m_inner_control.is_enabled())
                return;

            if (m_inner_control.contains_point(e.getPoint()))
            {
                m_inner_control.notify_mouse_click_event(e);
                console::debug("m_inner_control clicked");
            }

            control::process_mouse_click_event(e);
            invalidate();
        }

        void process_mouse_moved_event(events::mouse_moved_event& e) override
        {
            control::process_mouse_moved_event(e);

            if (!m_inner_control.is_visible() || !m_inner_control.is_enabled())
                return;

            if (m_inner_control.contains_point(e.position))
            {
                console::debug("m_inner_control inside");
                m_inner_control.notify_mouse_moved_event(e);
            }
        }

        void invalidate() const noexcept override
        {
            control::invalidate();
            m_inner_control.invalidate();
        }

        void validate() const noexcept override
        {
            control::validate();
            m_inner_control.validate();
        }

        auto is_invalidated() const noexcept -> bool override
        {
            return control::is_invalidated() || m_inner_control.is_invalidated();
        }

        void do_layout() override
        {
            if (!m_inner_control.is_visible() || !m_inner_control.is_enabled())
                return;

            const auto& position = get_actual_position();

            const auto size = get_size();
            const auto size_times_2 = size * 2;

            m_inner_control.set_actual_position(
                {position.get_x() + size, position.get_y() + size});

            const auto& actual_size = get_actual_size();
            m_inner_control.set_actual_size(
                { actual_size.get_width() - size_times_2,
                  actual_size.get_height() - size_times_2});

            m_inner_control.do_layout();
        }

        auto get_control_by_position(const point &point) const
    -> std::optional<std::reference_wrapper<const control>> override
        {
            if (!m_inner_control.is_visible() || !m_inner_control.is_enabled())
                return std::nullopt;

            auto result = m_inner_control.get_control_by_position(point);
            if (result.has_value())
                return result;

            return std::nullopt;
        }
    };
}