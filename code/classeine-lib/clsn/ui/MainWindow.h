#pragma once

#include "Control.h"

#include "impl/MainWindowImpl.h"

#include "clsn/core/Property.h"

#include "clsn/draw/Dimension.h"

#include "events/WindowEventManager.h"
#include "models/WindowModel.h"
#include "renderers/WindowRenderer.h"

namespace clsn::ui
{
    using namespace clsn::draw;
    using namespace clsn::ui::events;
    using namespace clsn::ui::models;
    using namespace clsn::ui::renderers;

    template <typename ControlType>
    class MainWindow final : public Control<WindowModel, WindowEventManager, WindowRenderer>
    {
        clsn::ui::impl::MainWindowImpl<MainWindow<ControlType>> m_impl;
        ControlType m_control;

    public:
        MainWindow()
        : m_impl{*this}
        {
            initVisibility();
            initSize();
        }

        [[nodiscard]] ControlType& getControl() noexcept
        {
            return m_control;
        }

        [[nodiscard]] const ControlType& getControl() const noexcept
        {
            return m_control;
        }


    private:
        void initVisibility()
        {
            setVisible(false);

            addVisibleChangedListener(
                [this](auto& e)
                {
                    if (e.getNewValue())
                    {
                        m_impl.show();
                    }
                    else
                    {
                        m_impl.hide();
                    }
                });
        }

        void initSize()
        {
            addSizeChangedListener([this](auto&)
                                   {
                                       m_impl.repaint();
                                   });
        }
    };
}