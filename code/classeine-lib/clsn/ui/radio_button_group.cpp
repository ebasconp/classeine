#include "radio_button_group.h"

#include "radio_button.h"

#include <iostream> //ETOTODO: REMOVE THIS

namespace clsn::ui
{
    void radio_button_group::add(std::shared_ptr<radio_button> a_radio_button)
    {
        init_events(*a_radio_button);
        m_radio_buttons.push_back(std::move(a_radio_button));
    }

    void radio_button_group::init_events(radio_button& a_radio_button)
    {
        a_radio_button.add_action_listener([this, &a_radio_button](auto&)
        {
            for (auto& ptr : m_radio_buttons)
            {
                if (ptr.get() == &a_radio_button)
                    continue;

                ptr->set_checked(false);
                ptr->invalidate();
            }
        });
    }
}