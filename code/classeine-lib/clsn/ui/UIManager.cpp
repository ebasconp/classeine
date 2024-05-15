#include "UIManager.h"

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
        std::cout << "UIManager instantiated" << std::endl; //ETOTODO REMOVE
    }
}