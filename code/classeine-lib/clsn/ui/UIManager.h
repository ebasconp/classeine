#pragma once

#include "clsn/core/Configuration.h"

namespace clsn::ui
{
    class UIManager final
    {
        clsn::core::Configuration m_configuration;

    public:
        UIManager(const UIManager&) = delete;
        UIManager(UIManager&&) = delete;

        UIManager& operator=(const UIManager&) = delete;
        UIManager& operator=(UIManager&&) = delete;

        ~UIManager() = default;

        static UIManager& getInstance();

    private:
        UIManager();
    };
}