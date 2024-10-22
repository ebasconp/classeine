// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/Container.h>

namespace clsn::ui
{
    /// @class ConstrainedContainerInfo
    /// @brief Holds a Control and its associated constraint.
    ///
    /// This class is a wrapper that contains a pointer to a Control and an associated
    /// Layout constraint. It provides access to the Control and constraint, allowing
    /// for constrained Layout management in a UI.
    /// @tparam Constraint The type of the Layout constraint associated with the Control.
    template <typename Constraint>
    class ConstrainedContainerInfo final
    {
        std::shared_ptr<Control> m_controlPtr;
        Constraint m_constraint;

    public:
        /// @brief Constructs a constrained Container info with a Control and its constraint.
        /// @param ctrl Shared pointer to a Control.
        /// @param constraint An object representing the Layout constraint.
        ConstrainedContainerInfo(std::shared_ptr<Control> ctrl, Constraint constraint)
        : m_controlPtr{std::move(ctrl)}
        , m_constraint{constraint}
        {
        }

        /// @brief Gets a shared pointer to the Control.
        /// @return A non-const shared pointer to the Control.
        [[nodiscard]] auto getControlPtr() { return m_controlPtr; }

        /// @brief Gets a shared pointer to the Control (const version).
        /// @return A const reference to the shared pointer of the Control.
        [[nodiscard]] auto getControlPtr() const -> const std::shared_ptr<Control>&  { return m_controlPtr; }

        /// @brief Gets the Layout constraint.
        /// @return A const reference to the Layout constraint.
        [[nodiscard]] auto getConstraint() const -> const Constraint& { return m_constraint; }

        /// @brief Gets the Layout constraint.
        /// @return A reference to the constraint.
        [[nodiscard]] auto getConstraint() -> Constraint& { return m_constraint; }
    };

    /// @class ConstrainedContainer
    /// @brief A Container that manages controls with associated constraints.
    ///
    /// This class serves as the base class for all containers that manage controls
    /// with Layout constraints. It provides functionality to add controls with their
    /// respective constraints and ensures the validity of these constraints.
    /// @tparam Constraint The type of the constraint associated with the controls in the Container.
    template <typename Constraint>
    class ConstrainedContainer : public Container<ConstrainedContainerInfo<Constraint>>
    {
    public:
        using ConstraintType = Constraint;
        using container_info = ConstrainedContainerInfo<Constraint>;

        /// @brief Constructs a constrained Container with a given section name.
        /// @param sectionName A string representing the name of the section.
        explicit ConstrainedContainer(std::string_view sectionName)
        : Container<container_info>{sectionName}
        {
        }

        /// @brief Destructor.
        ~ConstrainedContainer() override = default;

        /// @brief Adds a Control with the specified arguments for constructing the constraint.
        ///
        /// This method creates a constraint using the provided arguments, then adds the
        /// Control and the constraint to the Container after checking its validity.
        /// @tparam ControlType The type of the Control to be added.
        /// @tparam Args Variadic template parameters to create the constraint.
        /// @param ctrl Shared pointer to the Control.
        /// @param args Arguments to be forwarded to the constraint constructor.
        /// @return A shared pointer to the added Control.
        template <typename ControlType, typename... Args>
        auto add(std::shared_ptr<ControlType> ctrl, Args&&... args)
                    -> std::shared_ptr<ControlType>
        {
            Constraint _constraint{std::forward<Args>(args)...};
            checkIfValidBeforeAdding(_constraint);
            this->addElement(ctrl, std::move(_constraint));
            this->initNewControl(*ctrl);

            return ctrl;
        }

        /// @brief Converts a Container info object to a Control reference.
        /// @param e The Container info object.
        /// @return A reference to the Control.
        auto toControl(container_info& e) -> Control& override
        {
            return *e.getControlPtr();
        }

        /// @brief Converts a const Container info object to a const Control reference.
        /// @param e The Container info object.
        /// @return A const reference to the Control.
        auto toControl(const container_info& e) const -> const Control& override
        {
            return *e.getControlPtr();
        }

    protected:
        /// @brief Checks if the constraint is valid before adding.
        ///
        /// This function can be overridden to check the validity of a constraint before it is added.
        /// By default, it does nothing.
        /// @param constraint_ The constraint to be checked.
        virtual void checkIfValidBeforeAdding(const Constraint&) const
        {
            // Do nothing here
        }
    };
}