#pragma once

#include "UIManagerDefaults.h"

#include "clsn/draw/FontInfo.h"

#include "clsn/core/Entity.h"

#include <memory>
#include <string>
#include <string_view>

namespace clsn::ui
{
    using namespace clsn::draw;

    class UIManager final : public Entity
    {
        UIManagerDefaults m_defaults;
        std::unordered_map<FontInfo, std::string> m_pathsByFontInfo;

        static std::unique_ptr<UIManager> m_singleton;

    public:
        UIManager(const UIManager&) = delete;
        UIManager(UIManager&&) = delete;

        UIManager& operator=(const UIManager&) = delete;
        UIManager& operator=(UIManager&&) = delete;

        ~UIManager() = default;

        static UIManager& getInstance();
        static void init();
        static void finalize();

        template <typename T>
        const T& getDefault(std::string_view sectionName,
                        std::string_view key,
                        const T& altValue = {}) const
        {
            const auto value = m_defaults.get<T>(sectionName, key);
            if (!value.has_value())
            {
                const auto themeValue = m_defaults.get<T>("Theme", key);
                if (themeValue.has_value())
                    return themeValue->get();

                return altValue;
            }

            return value->get();
        }

        void addFontMapping(const FontInfo& fontInfo, std::string_view path);
        std::string_view getPathByFontInfo(const FontInfo&) const noexcept;

    private:
        UIManager();

        void populateDefaults();
        void populateFontMappings();
    };
}