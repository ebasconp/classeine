// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/RadioButtonGroup.h>

#include <clsn/ui/RadioButton.h>

namespace clsn::ui
{
    void RadioButtonGroup::add(std::shared_ptr<RadioButton> radioButton)
    {
        initRadioButtonGroupEvents(*radioButton);
        m_radioButtons.push_back(std::move(radioButton));
    }

    void RadioButtonGroup::initRadioButtonGroupEvents(RadioButton& radioButton)
    {
        radioButton.addActionListener([this, &radioButton](auto&)
        {
            for (auto& ptr : m_radioButtons)
            {
                if (ptr.get() == &radioButton)
                    continue;

                ptr->setChecked(false);
                ptr->invalidate();
            }
        });
    }
}