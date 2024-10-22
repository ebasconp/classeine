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
    class LayoutContainer;
}

namespace clsn::ui::layouts
{
    /// @brief Utility class for managing UI Layout information.
    class LayoutUtils : public clsn::core::NonInstantiable
    {
    public:
        /// @brief Converts the elements of a Layout Container to Layout info.
        /// This function maps the elements of a Layout Container to elements
        /// that can be processed by a Layout.
        ///
        /// @tparam LayoutType The type of the Layout.
        /// @param Container The Layout Container whose elements need to be converted.
        /// @return A vector of Layout element info specific to the Layout type.
        template <typename LayoutType>
        static auto to_layout_info(LayoutContainer<LayoutType>& Container)
                    -> typename LayoutType::LayoutElementInfoVector
        {
            typename LayoutType::LayoutElementInfoVector infos;

            auto elems = Container.getElements();

            std::transform(
                    elems.begin(), elems.end(),
                    std::back_inserter(infos), [](auto& e)
                    {
                        auto& c = *e.getControlPtr();

                        return typename LayoutType::LayoutElementInfo
                        {
                            { c.getActualPosition(), c.getActualPreferredSize() },
                            e.getConstraint(),
                            c.isVisible()
                        };
                    });

            return infos;
        }
    };
}