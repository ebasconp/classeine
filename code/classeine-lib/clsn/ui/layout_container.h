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
            this->add_element(ctrl, std::move(_constraint));
            this->init_new_control(*ctrl);
        }

        void do_layout() override
        {
            if (this->get_visible_count() == 0)
                return;

            m_layout.clear();

            for (auto& e : this->get_elements())
            {
                if (!e.m_control->is_visible())
                    continue;

                m_layout.add(
                    {e.m_control->get_actual_position(), e.m_control->get_actual_preferred_size()},
                    e.m_constraint);
            }

            m_layout.layout(this->get_actual_bounds());

            int count = this->get_count();
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

        auto to_control(control_and_constraint& e) -> control& override
        {
            return *e.m_control;
        }

        auto to_control(const control_and_constraint& e) const -> const control& override
        {
            return *e.m_control;
        }

    protected:
        virtual void check_if_valid_before_adding(const constraint&) const
        {
            // Do nothing here
        }
    };
}
