// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "container.h"

#include "window.h"


namespace clsn::ui
{
    template <typename Constraint>
    struct layout_container_control_and_constraint
    {
        std::shared_ptr<control> m_control;
        Constraint m_constraint;
    };

    template <typename Layout>
    class layout_container : public container<layout_container_control_and_constraint<typename Layout::constraint_type>>
    {
    public:
        using constraint = typename Layout::constraint_type;
        using control_and_constraint = layout_container_control_and_constraint<constraint>;

    private:
        std::vector<control_and_constraint> m_controls;
        Layout m_layout;

    public:
        explicit layout_container(std::string_view section_name)
        : container<control_and_constraint>{section_name}
        {
        }

        ~layout_container() override = default;

        auto get_layout() -> Layout&
        {
            return m_layout;
        }

        auto get_layout() const -> const Layout&
        {
            return m_layout;
        }

        template <typename ControlType, typename... Args>
        std::shared_ptr<ControlType> make_and_add(Args&&... args)
        {
            auto ptr = control::make<ControlType>();
            add(ptr, std::forward<Args>(args)...);

            return ptr;
        }

        template <typename... Args>
        void add(std::shared_ptr<control> ctrl, Args&&... args)
        {
            constraint _constraint{std::forward<Args>(args)...};
            check_if_valid_before_adding(_constraint);
            m_controls.emplace_back(ctrl, std::move(_constraint));
            this->init_new_control(*ctrl);
        }

        void iterate_elements(std::function<void(control_and_constraint&)> func) override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(m_controls[i]);
            }
        }

        void iterate_elements(std::function<void(const control_and_constraint&)> func) const override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(m_controls[i]);
            }
        }

        void iterate_controls(std::function<void(control&)> func) override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(*(m_controls[i].m_control));
            }
        }

        void iterate_controls(std::function<void(const control&)> func) const override
        {
            const auto count = m_controls.size();
            for (auto i = 0U; i < count; i++)
            {
                func(*(m_controls[i].m_control));
            }
        }

        [[nodiscard]] auto get_count() const noexcept -> int override
        {
            return static_cast<int>(m_controls.size());
        }

        auto get_element_at(int index) -> control_and_constraint& override
        {
            return m_controls[index];
        }

        auto get_element_at(int index) const -> const control_and_constraint& override
        {
            return m_controls[index];
        }

        auto operator[](int index) noexcept -> control& override
        {
            return *(m_controls[index].m_control);
        }

        auto operator[](int index) const noexcept -> const control& override
        {
            return *(m_controls[index].m_control);
        }

        void do_layout() override
        {
            if (this->get_visible_count() == 0)
                return;

            m_layout.clear();

            this->iterate_elements([&](control_and_constraint& e)
            {
                if (!e.m_control->is_visible())
                    return;

                m_layout.add(
                    {e.m_control->get_actual_position(), e.m_control->get_actual_preferred_size()},
                    e.m_constraint);
            });

            m_layout.layout(this->get_actual_bounds());

            int count = get_count();
            for (int i = 0, j = 0; i < count; i++)
            {
                auto& ctrl = (*this)[i];
                if (!ctrl.is_visible())
                    continue;

                auto& rgn = m_layout.get_element_at(j).m_region;

                ctrl.set_actual_position(rgn.get_position());
                ctrl.set_actual_size(rgn.get_size());

                j++;
            }
        }

        void set_parent_control(optional_reference<control> ctrl) override
        {
            control::set_parent_control(ctrl);

            iterate_controls([this](control& c) { c.set_parent_control(*this); });
        }

        void set_parent_window(optional_reference<window> wnd) override
        {
            control::set_parent_window(wnd);

            iterate_controls([&wnd](control& c) { c.set_parent_window(wnd); });
        }

    protected:
        virtual void check_if_valid_before_adding(const constraint&) const
        {
            // Do nothing here
        }
    };
}
