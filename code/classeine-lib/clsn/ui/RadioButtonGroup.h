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
        void initEvents(RadioButton& radioButton);
    };
}