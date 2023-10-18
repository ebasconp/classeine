#pragma once

#include "Control.h"

#include "clsn/core/Property.h"

#include <string>


namespace clsn::ui
{
    using namespace clsn::core;

    template <typename TControl>
    class MainWindow : public Control
    {
        Property<std::string> m_title { "Title" };

    public:
        const std::string& getTitle() const noexcept
        {
            return m_title.get();
        }

        void setTitle(const std::string& title)
        {
            m_title.set(title);
        }
    };
}