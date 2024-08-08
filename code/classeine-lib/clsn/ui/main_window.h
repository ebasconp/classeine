#pragma once

#include "window.h"

#include "impl/main_window_impl.h"

namespace clsn::ui
{
    using namespace clsn::draw;

    template <typename ControlType>
    class main_window final : public window
    {
        clsn::ui::impl::main_window_impl<main_window<ControlType>> m_impl;
        ControlType m_control;

    public:
        main_window()
        : window("main_window")
        , m_impl{*this}
        {
            init_visibility();
            init_size();
            load_window_defaults();

            UIManager::getInstance().addThemeChangedListener([this](auto&)
            {
                update_theme();
            });

            m_control.set_parent_window(*this);
        }

        [[nodiscard]] auto operator()() noexcept -> ControlType&
        {
            return m_control;
        }

        [[nodiscard]] auto operator()() const noexcept -> const ControlType&
        {
            return m_control;
        }

        void process_mouse_click_event(events::MouseClickEvent& e)
        {
            m_control.notify_mouse_click_event(e);
        }

        void process_mouse_moved_event(events::MouseMovedEvent& e)
        {
            window::process_mouse_moved_event(e);
            m_control.notify_mouse_moved_event(e);
        }

        auto get_control_by_position(const point& point) const ->
            std::optional<std::reference_wrapper<const control>> override
        {
            return m_control.get_control_by_position(point);
        }

    private:
        void load_window_defaults()
        {

        }

        void update_theme()
        {
            load_window_defaults();
            load_defaults();

            m_control.load_defaults();
            m_control.invalidate();
        }


        void init_visibility()
        {
            add_visible_changed_listener(
                [this](auto& e)
                {
                    if (e.get_new_value())
                    {
                        m_impl.show();
                    }
                    else
                    {
                        m_impl.hide();
                    }
                });
        }

        void init_size()
        {
            //auto& dimension = UIManager::getInstance().getDefault(
            //                "main_window", "size", dimension{300, 200});
            //ETOTODO: MOVE THIS TO THE THEME

            m_control.set_actual_size(dimension{800, 600});

            add_size_changed_listener([this](auto& e)
            {
                auto& newValue = e.get_new_value();
                m_control.set_actual_size(newValue);
                m_control.invalidate();
            });

            add_actual_size_changed_listener([this](auto& e)
            {
                auto& newValue = e.get_new_value();
                m_control.set_actual_size(newValue);
                m_control.invalidate();
            });
        }
    };
}