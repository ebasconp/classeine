// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/container.h>
#include <clsn/ui/window.h>

namespace clsn::ui
{
    /// @class constrained_container_info
    /// @brief Holds a control and its associated constraint.
    ///
    /// This class is a wrapper that contains a pointer to a control and an associated
    /// layout constraint. It provides access to the control and constraint, allowing
    /// for constrained layout management in a UI.
    /// @tparam Constraint The type of the layout constraint associated with the control.
    template <typename Constraint>
    class constrained_container_info final
    {
        std::shared_ptr<control> m_control_ptr;
        Constraint m_constraint;

    public:
        /// @brief Constructs a constrained container info with a control and its constraint.
        /// @param ctrl Shared pointer to a control.
        /// @param constraint An object representing the layout constraint.
        constrained_container_info(std::shared_ptr<control> ctrl, Constraint constraint)
        : m_control_ptr{std::move(ctrl)}
        , m_constraint{constraint}
        {
        }

        /// @brief Gets a shared pointer to the control.
        /// @return A non-const shared pointer to the control.
        [[nodiscard]] auto get_control_ptr() { return m_control_ptr; }

        /// @brief Gets a shared pointer to the control (const version).
        /// @return A const reference to the shared pointer of the control.
        [[nodiscard]] auto get_control_ptr() const -> const std::shared_ptr<control>&  { return m_control_ptr; }

        /// @brief Gets the layout constraint.
        /// @return A const reference to the layout constraint.
        [[nodiscard]] auto get_constraint() const -> const Constraint& { return m_constraint; }

        /// @brief Gets the layout constraint.
        /// @return A reference to the constraint.
        [[nodiscard]] auto get_constraint() -> Constraint& { return m_constraint; }
    };

    /// @class constrained_container
    /// @brief A container that manages controls with associated constraints.
    ///
    /// This class serves as the base class for all containers that manage controls
    /// with layout constraints. It provides functionality to add controls with their
    /// respective constraints and ensures the validity of these constraints.
    /// @tparam Constraint The type of the constraint associated with the controls in the container.
    template <typename Constraint>
    class constrained_container : public container<constrained_container_info<Constraint>>
    {
    public:
        using constraint = Constraint;
        using container_info = constrained_container_info<constraint>;

        /// @brief Constructs a constrained container with a given section name.
        /// @param sectionName A string representing the name of the section.
        explicit constrained_container(std::string_view sectionName)
        : container<container_info>{sectionName}
        {
        }

        /// @brief Destructor.
        ~constrained_container() override = default;

        /// @brief Adds a control with the specified arguments for constructing the constraint.
        ///
        /// This method creates a constraint using the provided arguments, then adds the
        /// control and the constraint to the container after checking its validity.
        /// @tparam ControlType The type of the control to be added.
        /// @tparam Args Variadic template parameters to create the constraint.
        /// @param ctrl Shared pointer to the control.
        /// @param args Arguments to be forwarded to the constraint constructor.
        /// @return A shared pointer to the added control.
        template <typename ControlType, typename... Args>
        auto add(std::shared_ptr<ControlType> ctrl, Args&&... args)
                    -> std::shared_ptr<ControlType>
        {
            constraint _constraint{std::forward<Args>(args)...};
            check_if_valid_before_adding(_constraint);
            this->add_element(ctrl, std::move(_constraint));
            this->init_new_control(*ctrl);

            return ctrl;
        }

        /// @brief Converts a container info object to a control reference.
        /// @param e The container info object.
        /// @return A reference to the control.
        auto to_control(container_info& e) -> control& override
        {
            return *e.get_control_ptr();
        }

        /// @brief Converts a const container info object to a const control reference.
        /// @param e The container info object.
        /// @return A const reference to the control.
        auto to_control(const container_info& e) const -> const control& override
        {
            return *e.get_control_ptr();
        }

    protected:
        /// @brief Checks if the constraint is valid before adding.
        ///
        /// This function can be overridden to check the validity of a constraint before it is added.
        /// By default, it does nothing.
        /// @param constraint_ The constraint to be checked.
        virtual void check_if_valid_before_adding(const constraint&) const
        {
            // Do nothing here
        }
    };
}