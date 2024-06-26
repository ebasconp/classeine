#include "RadioButtonGroup.h"

#include "RadioButton.h"

#include <iostream> //ETOTODO: REMOVE THIS

namespace clsn::ui
{
    void RadioButtonGroup::add(std::shared_ptr<RadioButton> radioButton)
    {
        initEvents(*radioButton);
        m_radioButtons.push_back(std::move(radioButton));
    }

    void RadioButtonGroup::initEvents(RadioButton& radioButton)
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