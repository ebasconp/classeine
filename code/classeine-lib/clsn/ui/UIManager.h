#pragma once

#include "UIManagerDefaults.h"

#include <string_view>

namespace clsn::ui
{
    using namespace clsn::draw;

    class UIManager final
    {
        UIManagerDefaults m_defaults;

    public:
        UIManager(const UIManager&) = delete;
        UIManager(UIManager&&) = delete;

        UIManager& operator=(const UIManager&) = delete;
        UIManager& operator=(UIManager&&) = delete;

        ~UIManager() = default;

        static UIManager& getInstance();

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

    private:
        UIManager();

        void populateDefaults();
    };
}