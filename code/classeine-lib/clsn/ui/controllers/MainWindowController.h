#pragma once

#include <string_view>

namespace clsn::ui::controllers
{
    class MainWindowController
    {
    public:
        [[nodiscard]] std::string_view getDefaultSectionName() const
        {
            return "MainWindow";
        }
    };
}