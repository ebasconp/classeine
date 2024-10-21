/// @file
/// @brief Utility functions related to UI layouts.
/// This file belongs to the Classeine project.
/// @copyright © 2024 Ernesto Bascón Pantoja
/// @license BSD-3-Clause

#pragma once

#include <clsn/core/NonInstantiable.h>
#include <algorithm>

namespace clsn::ui
{
    template <typename LayoutType>
    class layout_container;
}

namespace clsn::ui::layouts
{
    /// @brief Utility class for managing UI layout information.
    class layout_utils : public clsn::core::NonInstantiable
    {
    public:
        /// @brief Converts the elements of a layout container to layout info.
        /// This function maps the elements of a layout container to elements
        /// that can be processed by a layout.
        ///
        /// @tparam LayoutType The type of the layout.
        /// @param container The layout container whose elements need to be converted.
        /// @return A vector of layout element info specific to the layout type.
        template <typename LayoutType>
        static auto to_layout_info(layout_container<LayoutType>& container)
                    -> typename LayoutType::layout_element_info_vector
        {
            typename LayoutType::layout_element_info_vector infos;

            auto elems = container.get_elements();

            std::transform(
                    elems.begin(), elems.end(),
                    std::back_inserter(infos), [](auto& e)
                    {
                        auto& c = *e.get_control_ptr();

                        return typename LayoutType::layout_element_info
                        {
                            { c.getActualPosition(), c.get_actual_preferred_size() },
                            e.get_constraint(),
                            c.isVisible()
                        };
                    });

            return infos;
        }
    };
}