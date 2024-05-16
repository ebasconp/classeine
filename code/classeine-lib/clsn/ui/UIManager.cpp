#include "UIManager.h"

#include "defaults/ButtonDefaults.h"
#include "defaults/ThemeDefaults.h"

#include <iostream> //ETOTODO: Remove

namespace clsn::ui
{
    UIManager& UIManager::getInstance()
    {
        static UIManager instance;
        return instance;
    }

    UIManager::UIManager()
    {
        std::cout << "UIManager instantiated" << std::endl;

        populateDefaults();
    }


    void UIManager::populateDefaults()
    {
        defaults::ThemeDefaults::populateDefaults(m_defaults);
        defaults::ButtonDefaults::populateDefaults(m_defaults);
    }
}