// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include "container.h"

#include "clsn/core/system.h"

namespace clsn::ui
{
    template <typename InnerControlType>
    class mono_container : public container<InnerControlType>
    {
        InnerControlType m_inner_control;
        
    public:
        explicit mono_container(std::string_view section_name)
        : container<InnerControlType>(section_name)
        {
        }
        
        auto get_inner_control() -> InnerControlType& { return m_inner_control; }
        auto get_inner_control() const -> const InnerControlType& { return m_inner_control; }
        
        void iterate_elements(std::function<void(InnerControlType&)> func) override
        {
            func(m_inner_control);
        }

        void iterate_elements(std::function<void(const InnerControlType&)> func)  const override
        {
            func(m_inner_control);
        }
        
        void iterate_controls(std::function<void(control&)> func) override
        {
            func(m_inner_control);
        }

        void iterate_controls(std::function<void(const control&)> func) const override
        {
            func(m_inner_control);
        }

        auto get_count() const noexcept -> int override
        {
            return 1;
        }

        auto get_element_at(int index) -> InnerControlType& override
        {
            if (index > 0) clsn::core::system::panic("Index cannot be greater than zero");

            return m_inner_control;
        }

        auto get_element_at(int index) const -> const InnerControlType& override
        {
            if (index > 0) clsn::core::system::panic("Index cannot be greater than zero");

            return m_inner_control;
        }

        auto operator[](int index) noexcept -> control& override
        {
            return get_element_at(index);
        }

        auto operator[](int index) const noexcept -> const control& override
        {
            return get_element_at(index);
        }
    };
}