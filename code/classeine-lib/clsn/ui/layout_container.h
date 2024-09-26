// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/container.h>

#include <clsn/ui/window.h>

#include <clsn/ui/layouts/layout_utils.h>

namespace clsn::ui
{
    template <typename Constraint>
    class layout_container_control_and_constraint final
    {
        std::shared_ptr<control> m_control_ptr;
        Constraint m_constraint;

    public:
        layout_container_control_and_constraint(std::shared_ptr<control> ctrl, Constraint constraint)
        : m_control_ptr{std::move(ctrl)}
        , m_constraint{constraint}
        {
        }

        [[nodiscard]] auto get_control_ptr() { return m_control_ptr; }
        [[nodiscard]] auto get_control_ptr() const -> const std::shared_ptr<control>&  { return m_control_ptr; }

        [[nodiscard]] auto get_constraint() const -> const Constraint& { return m_constraint; }
        [[nodiscard]] auto get_constraint() -> Constraint& { return m_constraint; }
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

            auto infos = layouts::layout_utils::to_layout_info(*this);

            m_layout.do_layout(this->get_actual_bounds(), infos);

            int count = this->get_count();
            for (int i = 0, j = 0; i < count; i++)
            {
                auto& ctrl = (*this)[i];
                if (!ctrl.is_visible())
                    continue;

                auto& rgn = infos[i].get_output_region();

                ctrl.set_actual_position(rgn.get_position());
                ctrl.set_actual_size(rgn.get_size());

                j++;
            }
        }

        auto to_control(control_and_constraint& e) -> control& override
        {
            return *e.get_control_ptr();
        }

        auto to_control(const control_and_constraint& e) const -> const control& override
        {
            return *e.get_control_ptr();
        }

    protected:
        virtual void check_if_valid_before_adding(const constraint&) const
        {
            // Do nothing here
        }
    };
}
