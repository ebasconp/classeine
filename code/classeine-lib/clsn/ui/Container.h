// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/PaintableControl.h>
#include <clsn/ui/UIManager.h>

#include <clsn/ui/Window.h>

#include <algorithm>
#include <ranges>

namespace clsn::ui
{
    /// @brief Represents a generic Container for UI elements.
    ///
    /// This class serves as a Container that can hold UI elements along with their
    /// Layout constraints. The key difference between an Element and a Control is that
    /// an Element is the Entity stored in the Container, likely representing a Control
    /// with additional information, such as Layout constraints.
    ///
    /// @tparam ElementType The type of elements stored in the Container.
    template <typename ElementType>
    class Container : public PaintableControl
    {
        using ElementVectorType = std::vector<ElementType>;
        using ControlVectorType = std::vector<Control>;

        mutable bool m_needsToPaintTheContainer;

        ElementVectorType m_elements;

    public:
        /// @brief Constructs a Container with the specified section name.
        ///
        /// @param sectionName The name of the section for this Container.
        explicit Container(std::string_view sectionName)
        : PaintableControl{sectionName}
        , m_needsToPaintTheContainer{false}
        {
            loadContainerDefaults();
            initContainerEvents();
        }

        CLSN_FULL_PROPERTY_WITH_DEFAULT_VALUE(Margin, int, true, 0)

    protected:
        /// @brief Adds a new element to the Container. Used only for derived
        /// classes to add actual elements instead of only controls.
        ///
        /// @tparam Args Variadic template arguments for constructing the element.
        /// @param args The arguments used to construct the element.
        template <typename... Args>
        void addElement(Args&&... args)
        {
            m_elements.emplace_back(std::forward<Args>(args)...);
        }

    public:
        /// @brief Retrieves a subrange of the elements in the Container.
        ///
        /// @return A subrange of the elements in the Container.
        auto getElements()
                -> std::ranges::subrange<
                    typename ElementVectorType::iterator>
        {
            return std::ranges::subrange{m_elements.begin(), m_elements.end()};
        }

        /// @brief Retrieves a view of the controls in the Container.
        ///
        /// @return A view of the controls corresponding to the elements in the Container.
        auto getControls()
        {
            auto r = getElements();
            return std::ranges::transform_view(r, [this](ElementType& e) -> Control&
            {
               return toControl(e);
            });
        }

        /// @brief Retrieves a const subrange of the elements in the Container.
        ///
        /// @return A const subrange of the elements in the Container.
        auto getElements() const
                -> std::ranges::subrange<typename ElementVectorType::const_iterator>
        {
            return std::ranges::subrange{m_elements.cbegin(), m_elements.cend()};
        }

        /// @brief Retrieves a const view of the controls in the Container.
        ///
        /// @return A const view of the controls corresponding to the elements in the Container.
        auto getControls() const
        {
            auto r = getElements();
            return std::ranges::transform_view(r, [this](const ElementType& e) -> const Control&
            {
               return toControl(e);
            });
        }

        /// @brief Converts an ElementType to a Control reference.
        ///
        /// @param e The element to convert.
        /// @return A reference to the corresponding Control.
        virtual auto toControl(ElementType& e) -> Control& = 0;

        /// @brief Converts a const ElementType to a const Control reference.
        ///
        /// @param e The element to convert.
        /// @return A const reference to the corresponding Control.
        virtual auto toControl(const ElementType& e) const -> const Control& = 0;

        /// @brief Gets the number of elements in the Container.
        ///
        /// @return The count of elements in the Container.
        auto getCount() const noexcept -> int
        {
            return static_cast<int>(m_elements.size());
        }

        /// @brief Retrieves the element at the specified index.
        ///
        /// @param index The index of the element.
        /// @return A reference to the element at the specified index.
        auto getElementAt(int index) -> ElementType&
        {
            return m_elements[index];
        }

        /// @brief Retrieves the element at the specified index as const.
        ///
        /// @param index The index of the element.
        /// @return A const reference to the element at the specified index.
        auto getElementAt(int index) const -> const ElementType&
        {
            return m_elements[index];
        }

        /// @brief Overloads the subscript operator to access controls.
        ///
        /// @param index The index of the element.
        /// @return A reference to the Control at the specified index.
        auto operator[](int index) noexcept -> Control&
        {
            return toControl(m_elements[index]);
        }

        /// @brief Overloads the subscript operator to access controls as const.
        ///
        /// @param index The index of the element.
        /// @return A const reference to the Control at the specified index.
        auto operator[](int index) const noexcept -> const Control&
        {
            return toControl(m_elements[index]);
        }

        /// @brief Checks if the Container is empty.
        ///
        /// @return True if the Container is empty, false otherwise.
        [[nodiscard]] auto isEmpty() const -> bool
        {
            return m_elements.empty();
        }

        /// @brief Invalidates the Container, requiring it to be repainted.
        void invalidate() const noexcept override
        {
            m_needsToPaintTheContainer = true;

            for (auto& c : getControls())
            {
                c.invalidate();
            }
        }

        /// @brief Validates the Container, marking it as painted.
        void validate() const noexcept override
        {
            m_needsToPaintTheContainer = false;

            for (auto& c : getControls())
            {
                c.validate();
            }
        }

        /// @brief Checks if the Container needs painting.
        ///
        /// @return True if the Container needs painting, false otherwise.
        auto needsToPaintTheContainer() const noexcept -> bool
        {
            return m_needsToPaintTheContainer;
        }

        /// @brief Checks if the Container or its controls are invalidated.
        ///
        /// @return True if the Container is invalidated, false otherwise.
        auto isInvalidated() const noexcept -> bool override
        {
            if (m_needsToPaintTheContainer && isEmpty())
                return true;

            return std::ranges::any_of(getControls(), [this](const Control& c) -> bool
            {
                return c.isInvalidated();
            });
        }

        /// @brief Gets the count of visible controls in the Container.
        ///
        /// @return The count of visible controls.
        auto getVisibleCount() const -> int
        {
            return static_cast<int>(std::count_if(m_elements.cbegin(), m_elements.cend(),
                [this](const ElementType& e) -> bool
                    {
                        return toControl(e).isVisible();
                    }
            ));
        }

        /// @brief Loads default settings for the Container and its controls.
        void loadDefaults() override
        {
            Control::loadDefaults();

            loadContainerDefaults();

            for (auto& c : getControls())
            {
                c.loadDefaults();
            }
        }

        /// @brief Gets the Control at the specified position.
        ///
        /// @param Point The position to check.
        /// @return An optional reference to the Control at the position.
        auto getControlByPosition(const draw::Point &Point) const
                -> core::constOptionalReference<Control> override
        {
            for (auto& c : getControls())
            {
                if (!c.isVisible() || !c.isEnabled())
                    continue;

                auto result = c.getControlByPosition(Point);
                if (result.hasValue())
                    return result;
            }

            return {};
        }

        /// @brief Sets the parent Window for the Container and its controls.
        ///
        /// @param pw The optional reference to the parent Window.
        void setParentWindow(core::OptionalReference<Window> pw) override
        {
            Control::setParentWindow(pw);

            for (auto& c : getControls())
            {
                c.setParentWindow(pw);
            }
        }

        /// @brief Sets the parent Control for the Container and its controls.
        ///
        /// @param parent_control The optional reference to the parent Control.
        void setParentControl(core::OptionalReference<Control> parent_control) override
        {
            Control::setParentControl(parent_control);

            for (auto& c : getControls())
            {
                c.setParentControl(*this);
            }
        }

    protected:
        void initNewControl(Control& control)
        {
            control.setParentWindow(getParentWindow());
            control.setParentControl(*this);

            control.addVisibleChangedListener(
                [this](auto&)
                {
                    doLayout();
                    invalidate();
                });
        }

        void processMouseClickEvent(events::MouseClickEvent& e) override
        {
            for (auto& c : getControls())
            {
                if (!c.isVisible() || !c.isEnabled())
                    continue;

                if (c.containsPoint(e.getPoint()))
                {
                    c.notifyMouseClickEvent(e);
                    break;
                }
            }

            Control::processMouseClickEvent(e);
        }

        void processMouseMovedEvent(events::MouseMovedEvent& e) override
        {
            Control::processMouseMovedEvent(e);

            for (auto& c : getControls())
            {
                if (!c.isVisible() || !c.isEnabled())
                    continue;

                if (c.containsPoint(e.getPosition()))
                {
                    c.notifyMouseMovedEvent(e);
                    break;
                }
            }
        }

    private:
        void initContainerEvents()
        {
            addEnabledChangedListener([this](auto& e)
            {
                for (auto& c : getControls())
                {
                    c.setEnabled(e.get_new_value());
                }
            });

            addActualSizeChangedListener(
                [this](auto& )
                {
                    doLayout();
                });
        }

        void loadContainerDefaults()
        {
            auto& uiManager = clsn::ui::UIManager::get_instance();
            auto sectionName = getDefaultSectionName();

            setBackgroundColor(uiManager.getColor(
                sectionName, "containerBackgroundColor"));

            setForegroundColor(uiManager.getColor(
                sectionName, "containerForegroundColor"));
        }
    };
}
