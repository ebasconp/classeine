#include "ControlBase.h"

namespace clsn::ui
{
    ControlBase::ControlBase(std::string_view sectionName)
    {
        auto& uiManager = UIManager::getInstance();

        setBackgroundColor(
            uiManager.getDefault(sectionName, "backgroundColor", Colors::RED));

        setForegroundColor(uiManager.getDefault(
            sectionName, "foregroundColor", Colors::WHITE));

        setFont(uiManager.getDefault(sectionName, "font", Font{}));
    }
}