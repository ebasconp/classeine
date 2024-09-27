// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/container.h>

#include <clsn/ui/window.h>

namespace clsn::ui
{
    template <typename Constraint>
    class constrained_container_info final
    {
        std::shared_ptr<control> m_control_ptr;
        Constraint m_constraint;

    public:
        constrained_container_info(std::shared_ptr<control> ctrl, Constraint constraint)
        : m_control_ptr{std::move(ctrl)}
        , m_constraint{constraint}
        {
        }

        [[nodiscard]] auto get_control_ptr() { return m_control_ptr; }
        [[nodiscard]] auto get_control_ptr() const -> const std::shared_ptr<control>&  { return m_control_ptr; }

        [[nodiscard]] auto get_constraint() const -> const Constraint& { return m_constraint; }
        [[nodiscard]] auto get_constraint() -> Constraint& { return m_constraint; }
    };

    template <typename Constraint>
    class constrained_container : public container<constrained_container_info<Constraint>>
    {
    public:
        using constraint = Constraint;
        using container_info = constrained_container_info<constraint>;

        explicit constrained_container(std::string_view section_name)
        : container<container_info>{section_name}
        {
        }

        ~constrained_container() override = default;

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

        auto to_control(container_info& e) -> control& override
        {
            return *e.get_control_ptr();
        }

        auto to_control(const container_info& e) const -> const control& override
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
