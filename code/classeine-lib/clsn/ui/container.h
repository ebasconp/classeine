// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <clsn/ui/paintable_control.h>
#include <clsn/ui/ui_manager.h>

#include <clsn/ui/window.h>

#include <bits/ranges_algo.h>
#include <ranges>

namespace clsn::ui
{
    /// @brief Represents a generic container for UI elements.
    ///
    /// This class serves as a container that can hold UI elements along with their
    /// layout constraints. The key difference between an Element and a Control is that
    /// an Element is the entity stored in the container, likely representing a control
    /// with additional information, such as layout constraints.
    ///
    /// @tparam ElementType The type of elements stored in the container.
    template <typename ElementType>
    class container : public paintable_control
    {
        using element_vector_type = std::vector<ElementType>;
        using control_vector_type = std::vector<control>;

        mutable bool m_needs_to_paint_the_container;

        element_vector_type m_elements;

    public:
        /// @brief Constructs a container with the specified section name.
        ///
        /// @param section_name The name of the section for this container.
        explicit container(std::string_view section_name)
        : paintable_control{section_name}
        , m_needs_to_paint_the_container{false}
        {
            load_container_defaults();
            init_container_events();
        }

        CLSN_PROPERTY_VAL(margin, int, true, 0)

    protected:
        /// @brief Adds a new element to the container. Used only for derived
        /// classes to add actual elements instead of only controls.
        ///
        /// @tparam Args Variadic template arguments for constructing the element.
        /// @param args The arguments used to construct the element.
        template <typename... Args>
        void add_element(Args&&... args)
        {
            m_elements.emplace_back(std::forward<Args>(args)...);
        }

    public:
        /// @brief Retrieves a subrange of the elements in the container.
        ///
        /// @return A subrange of the elements in the container.
        auto get_elements()
                -> std::ranges::subrange<
                    typename element_vector_type::iterator>
        {
            return std::ranges::subrange{m_elements.begin(), m_elements.end()};
        }

        /// @brief Retrieves a view of the controls in the container.
        ///
        /// @return A view of the controls corresponding to the elements in the container.
        auto get_controls()
        {
            auto r = get_elements();
            return std::ranges::transform_view(r, [this](ElementType& e) -> control&
            {
               return to_control(e);
            });
        }

        /// @brief Retrieves a const subrange of the elements in the container.
        ///
        /// @return A const subrange of the elements in the container.
        auto get_elements() const
                -> std::ranges::subrange<typename element_vector_type::const_iterator>
        {
            return std::ranges::subrange{m_elements.cbegin(), m_elements.cend()};
        }

        /// @brief Retrieves a const view of the controls in the container.
        ///
        /// @return A const view of the controls corresponding to the elements in the container.
        auto get_controls() const
        {
            auto r = get_elements();
            return std::ranges::transform_view(r, [this](const ElementType& e) -> const control&
            {
               return to_control(e);
            });
        }

        /// @brief Converts an ElementType to a control reference.
        ///
        /// @param e The element to convert.
        /// @return A reference to the corresponding control.
        virtual auto to_control(ElementType& e) -> control& = 0;

        /// @brief Converts a const ElementType to a const control reference.
        ///
        /// @param e The element to convert.
        /// @return A const reference to the corresponding control.
        virtual auto to_control(const ElementType& e) const -> const control& = 0;

        /// @brief Gets the number of elements in the container.
        ///
        /// @return The count of elements in the container.
        auto get_count() const noexcept -> int
        {
            return static_cast<int>(m_elements.size());
        }

        /// @brief Retrieves the element at the specified index.
        ///
        /// @param index The index of the element.
        /// @return A reference to the element at the specified index.
        auto get_element_at(int index) -> ElementType&
        {
            return m_elements[index];
        }

        /// @brief Retrieves the element at the specified index as const.
        ///
        /// @param index The index of the element.
        /// @return A const reference to the element at the specified index.
        auto get_element_at(int index) const -> const ElementType&
        {
            return m_elements[index];
        }

        /// @brief Overloads the subscript operator to access controls.
        ///
        /// @param index The index of the element.
        /// @return A reference to the control at the specified index.
        auto operator[](int index) noexcept -> control&
        {
            return to_control(m_elements[index]);
        }

        /// @brief Overloads the subscript operator to access controls as const.
        ///
        /// @param index The index of the element.
        /// @return A const reference to the control at the specified index.
        auto operator[](int index) const noexcept -> const control&
        {
            return to_control(m_elements[index]);
        }

        /// @brief Checks if the container is empty.
        ///
        /// @return True if the container is empty, false otherwise.
        [[nodiscard]] auto is_empty() const -> bool
        {
            return m_elements.empty();
        }

        /// @brief Invalidates the container, requiring it to be repainted.
        void invalidate() const noexcept override
        {
            m_needs_to_paint_the_container = true;

            for (auto& c : get_controls())
            {
                c.invalidate();
            }
        }

        /// @brief Validates the container, marking it as painted.
        void validate() const noexcept override
        {
            m_needs_to_paint_the_container = false;

            for (auto& c : get_controls())
            {
                c.validate();
            }
        }

        /// @brief Checks if the container needs painting.
        ///
        /// @return True if the container needs painting, false otherwise.
        auto needs_to_paint_the_container() const noexcept -> bool
        {
            return m_needs_to_paint_the_container;
        }

        /// @brief Checks if the container or its controls are invalidated.
        ///
        /// @return True if the container is invalidated, false otherwise.
        auto is_invalidated() const noexcept -> bool override
        {
            if (m_needs_to_paint_the_container && is_empty())
                return true;

            return std::ranges::any_of(get_controls(), [this](const control& c) -> bool
            {
                return c.is_invalidated();
            });
        }

        /// @brief Gets the count of visible controls in the container.
        ///
        /// @return The count of visible controls.
        auto get_visible_count() const -> int
        {
            return std::count_if(m_elements.cbegin(), m_elements.cend(),
                [this](const ElementType& e) -> bool
                    {
                        return to_control(e).is_visible();
                    }
            );
        }

        /// @brief Loads default settings for the container and its controls.
        void load_defaults() override
        {
            control::load_defaults();

            load_container_defaults();

            for (auto& c : get_controls())
            {
                c.load_defaults();
            }
        }

        /// @brief Gets the control at the specified position.
        ///
        /// @param point The position to check.
        /// @return An optional reference to the control at the position.
        auto get_control_by_position(const draw::point &point) const
                -> const_optional_reference<control> override
        {
            for (auto& c : get_controls())
            {
                if (!c.is_visible() || !c.is_enabled())
                    continue;

                return c.get_control_by_position(point);
            }

            return std::nullopt;
        }

        /// @brief Sets the parent window for the container and its controls.
        ///
        /// @param pw The optional reference to the parent window.
        void set_parent_window(optional_reference<window> pw) override
        {
            control::set_parent_window(pw);

            for (auto& c : get_controls())
            {
                c.set_parent_window(pw);
            }
        }

        /// @brief Sets the parent control for the container and its controls.
        ///
        /// @param parent_control The optional reference to the parent control.
        void set_parent_control(optional_reference<control> parent_control) override
        {
            control::set_parent_control(parent_control);

            for (auto& c : get_controls())
            {
                c.set_parent_control(*this);
            }
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
            for (auto& c : get_controls())
            {
                if (!c.is_visible() || !c.is_enabled())
                    continue;

                if (c.contains_point(e.get_point()))
                {
                    c.notify_mouse_click_event(e);
                    break;
                }
            }

            control::process_mouse_click_event(e);
        }

        void process_mouse_moved_event(events::mouse_moved_event& e) override
        {
            control::process_mouse_moved_event(e);

            for (auto& c : get_controls())
            {
                if (!c.is_visible() || !c.is_enabled())
                    continue;

                if (c.contains_point(e.get_position()))
                {
                    c.notify_mouse_moved_event(e);
                    break;
                }
            }
        }

    private:
        void init_container_events()
        {
            add_enabled_changed_listener([this](auto& e)
            {
                for (auto& c : get_controls())
                {
                    c.set_enabled(e.get_new_value());
                }
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
