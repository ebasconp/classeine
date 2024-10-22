// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#pragma once

#include <memory>
#include <vector>

namespace clsn::ui
{
    class RadioButton;

    class RadioButtonGroup final
    {
        std::vector<std::shared_ptr<RadioButton>> m_radioButtons;

    public:
        void add(std::shared_ptr<RadioButton> radioButton);

    private:
        void initRadioButtonGroupEvents(RadioButton& radioButton);
    };
}