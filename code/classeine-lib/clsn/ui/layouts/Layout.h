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
    /// @tparam Constraint The type of constraint used in the Layout.
    template <typename Constraint>
    class Layout
    {
    public:
        /// @brief Information about a Layout element.
        class LayoutElementInfo final
        {
            draw::Region m_outputRegion;
            const draw::Region m_inputRegion;
            Constraint m_constraint;
            bool m_visible;

        public:
            /// @brief Constructs a LayoutElementInfo object.
            /// @param input_region The input Region of the element.
            /// @param constraint The constraint associated with the element.
            /// @param visible The visibility status of the element.
            LayoutElementInfo(const draw::Region& input_region, const Constraint& constraint, bool visible)
            : m_outputRegion{0, 0, 0, 0}
            , m_inputRegion{input_region}
            , m_constraint{constraint}
            , m_visible{visible}
            {
            }

            /// @brief Gets the output Region of the element.
            /// @return A constant reference to the output Region.
            auto getOutputRegion() const -> const draw::Region& { return m_outputRegion; }

            /// @brief Sets the output Region of the element.
            /// @param output_region The new output Region to set.
            void setOutputRegion(const draw::Region& output_region) { m_outputRegion = output_region; }

            /// @brief Gets the input Region of the element.
            /// @return A constant reference to the input Region.
            auto getInputRegion() const -> const draw::Region& { return m_inputRegion; }

            /// @brief Gets the constraint of the element.
            /// @return A constant reference to the constraint.
            auto getConstraint() const -> const Constraint& { return m_constraint; }

            /// @brief Checks if the element is visible.
            /// @return True if the element is visible, false otherwise.
            auto isVisible() const -> bool { return m_visible; }
        };

        /// @brief A vector of LayoutElementInfo objects.
        using LayoutElementInfoVector = std::vector<LayoutElementInfo>;

        /// @brief Virtual destructor.
        virtual ~Layout() = default;

        /// @brief Performs Layout in the specified Region using the provided element info vector.
        /// @param rgn The Region in which to perform the Layout.
        /// @param layout_element_info_vec The vector of Layout element info.
        virtual void doLayout(const draw::Region& rgn, LayoutElementInfoVector& layout_element_info_vec) const = 0;
    };
}