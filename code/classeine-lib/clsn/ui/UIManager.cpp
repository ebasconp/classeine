#include "UIManager.h"

#include "clsn/core/Panic.h"

#include "defaults/ButtonDefaults.h"
#include "defaults/HBoxContainerDefaults.h"
#include "defaults/LabelDefaults.h"
#include "defaults/MainWindowDefaults.h"
#include "defaults/ThemeDefaults.h"
#include "defaults/ToggleButtonDefaults.h"
#include "defaults/VBoxContainerDefaults.h"

#include <iostream> //ETOTODO: Remove

namespace clsn::ui
{
    std::unique_ptr<UIManager> UIManager::m_singleton;

    UIManager& UIManager::getInstance()
    {
        if (m_singleton == nullptr)
            clsn::core::Panic(
                "UIManager is not initialized. Run UIManager::init() at the "
                "beginning of your application");

        return *m_singleton;
    }

    void UIManager::init()
    {
        m_singleton = std::unique_ptr<UIManager>(new UIManager());
    }

    void UIManager::finalize()
    {
        m_singleton.reset();
    }

    void UIManager::addFontMapping(const FontInfo& fontInfo,
                                   std::string_view path)
    {
        m_pathsByFontInfo.insert(std::make_pair(fontInfo, std::string{path}));
    }

    UIManager::UIManager()
    {
        std::cout << "UIManager instantiated" << std::endl;

        populateFontMappings();
        populateDefaults();
    }

    void UIManager::populateFontMappings()
    {
        addFontMapping(
            FontInfo{"Nimbus", FontStyle::REGULAR},
            "/usr/share/fonts/opentype/urw-base35/NimbusSans-Regular.otf");
    }

    void UIManager::populateDefaults()
    {
        defaults::ThemeDefaults::populateDefaults(m_defaults);

        defaults::ButtonDefaults::populateDefaults(m_defaults);
        defaults::HBoxContainerDefaults::populateDefaults(m_defaults);
        defaults::LabelDefaults::populateDefaults(m_defaults);
        defaults::MainWindowDefaults::populateDefaults(m_defaults);
        defaults::ToggleButtonDefaults::populateDefaults(m_defaults);
        defaults::VBoxContainerDefaults::populateDefaults(m_defaults);
    }

    std::string_view UIManager::getPathByFontInfo(
        const FontInfo& fontInfo) const noexcept
    {
        auto it = m_pathsByFontInfo.find(fontInfo);
        if (it == m_pathsByFontInfo.end())
            return "";

        return it->second;
    }
}