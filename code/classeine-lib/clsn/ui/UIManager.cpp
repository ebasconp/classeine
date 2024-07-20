#include "UIManager.h"

#include "clsn/core/Panic.h"

#include "amatista/AmatistaUISkin.h"

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
        using namespace clsn::ui::amatista;

        makeAndLoadSkin<AmatistaUISkin>();
    }

    auto UIManager::getPathByFontInfo(const FontInfo& fontInfo) const noexcept -> std::string_view
    {
        auto it = m_pathsByFontInfo.find(fontInfo);
        if (it == m_pathsByFontInfo.end())
            return "";

        return it->second;
    }

    auto UIManager::getRendererByControl(const Control& ctrl) const -> std::shared_ptr<IRenderer>
    {
        return m_skin->getRendererByControl(ctrl);
    }

    auto UIManager::getColor(std::string_view sectionName, std::string_view name) const -> const Color&
    {
        return m_skin->getColor(sectionName, name);
    }

    auto UIManager::getDimension(std::string_view sectionName, std::string_view name) const -> const Dimension&
    {
        return m_skin->getDimension(sectionName, name);
    }

    auto UIManager::getFont(std::string_view sectionName, std::string_view name) const -> const Font&
    {
        return m_skin->getFont(sectionName, name);
    }

    auto UIManager::installTheme(const std::string& themeName) -> bool
    {
        return m_skin->installThemeByName(themeName);
    }

    auto UIManager::addThemeChangedListener(EventListener<EmptyEvent> listener) -> int
    {
        return m_skin->addThemeChangedListener(listener);
    }

    auto UIManager::getCurrentThemeName() const -> const std::string&
    {
        return m_skin->getCurrentThemeName();
    }
}