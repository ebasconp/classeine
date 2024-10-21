/// @file
/// @brief Base class for UI layouts in the Classeine project.
/// This file belongs to the Classeine project.
/// @copyright © 2024 Ernesto Bascón Pantoja
/// @license BSD-3-Clause

#pragma once

#include <clsn/draw/Region.h>
#include <vector>

namespace clsn::ui::layouts
{
    /// @brief Template base class for UI layouts.
    /// @tparam Constraint The type of constraint used in the layout.
    template <typename Constraint>
    class layout
    {
    public:
        /// @brief Information about a layout element.
        class layout_element_info final
        {
            draw::Region m_output_region;
            const draw::Region m_input_region;
            Constraint m_constraint;
            bool m_visible;

        public:
            /// @brief Constructs a layout_element_info object.
            /// @param input_region The input Region of the element.
            /// @param constraint The constraint associated with the element.
            /// @param visible The visibility status of the element.
            layout_element_info(const draw::Region& input_region, const Constraint& constraint, bool visible)
            : m_output_region{0, 0, 0, 0}
            , m_input_region{input_region}
            , m_constraint{constraint}
            , m_visible{visible}
            {
            }

            /// @brief Gets the output Region of the element.
            /// @return A constant reference to the output Region.
            auto get_output_region() const -> const draw::Region& { return m_output_region; }

            /// @brief Sets the output Region of the element.
            /// @param output_region The new output Region to set.
            void set_output_region(const draw::Region& output_region) { m_output_region = output_region; }

            /// @brief Gets the input Region of the element.
            /// @return A constant reference to the input Region.
            auto get_input_region() const -> const draw::Region& { return m_input_region; }

            /// @brief Gets the constraint of the element.
            /// @return A constant reference to the constraint.
            auto get_constraint() const -> const Constraint& { return m_constraint; }

            /// @brief Checks if the element is visible.
            /// @return True if the element is visible, false otherwise.
            auto isVisible() const -> bool { return m_visible; }
        };

        /// @brief A vector of layout_element_info objects.
        using layout_element_info_vector = std::vector<layout_element_info>;

        /// @brief Virtual destructor.
        virtual ~layout() = default;

        /// @brief Performs layout in the specified Region using the provided element info vector.
        /// @param rgn The Region in which to perform the layout.
        /// @param layout_element_info_vec The vector of layout element info.
        virtual void do_layout(const draw::Region& rgn, layout_element_info_vector& layout_element_info_vec) const = 0;
    };
}