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
    class mono_container : public container<std::shared_ptr<InnerControlType>>
    {
        using element_type = std::shared_ptr<InnerControlType>;
    public:
        explicit mono_container(std::string_view section_name)
        : container<element_type>(section_name)
        {
            auto ctrl = control::make<InnerControlType>();
            this->add_element(ctrl);
        }
        
        auto get_inner_control() -> InnerControlType& { return *this->get_element_at(0); }
        auto get_inner_control() const -> const InnerControlType& { return *this->get_element_at(0); }
        
        auto to_control(element_type& e) -> control& override
        {
            return *e;
        }

        auto to_control(const element_type& e) const -> const control& override
        {
            return *e;
        }
    };
}