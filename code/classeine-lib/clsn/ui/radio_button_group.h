#pragma once

#include <memory>
#include <vector>

namespace clsn::ui
{
    class radio_button;

    class radio_button_group final
    {
        std::vector<std::shared_ptr<radio_button>> m_radio_buttons;

    public:
        void add(std::shared_ptr<radio_button> a_radio_button);

    private:
        void init_events(radio_button& a_radio_button);
    };
}