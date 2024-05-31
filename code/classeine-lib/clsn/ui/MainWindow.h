#pragma once

#include "Control.h"

#include "impl/MainWindowImpl.h"

#include "clsn/core/Property.h"

#include "clsn/draw/Dimension.h"

#include "renderers/MainWindowRenderer.h"

namespace clsn::ui
{
    using namespace clsn::draw;
    using namespace clsn::ui::renderers;

    template <typename ControlType>
    class MainWindow final
    {
        clsn::ui::impl::MainWindowImpl<MainWindow<ControlType>> m_impl;
        ControlType m_control;

    public:
        MainWindow()
        : m_impl{*this}
        {
            initVisibility();
            initSize();

            initDefaults();
        }

        [[nodiscard]] ControlType& operator()() noexcept { return m_control; }

        [[nodiscard]] const ControlType& operator()() const noexcept
        {
            return m_control;
        }

        CLSN_BOOL_PROPERTY_VAL(Visible, true, false);
        CLSN_BOOL_PROPERTY_VAL(Resizable, true, true);

        CLSN_PROPERTY(Size, Dimension, true);
        CLSN_PROPERTY(MinimumSize, Dimension, true)

        void processMouseClickEvent(events::MouseClickEvent& e)
        {
            m_control.processMouseClickEvent(e);
        }

    private:
        void initDefaults()
        {
            setMinimumSize(UIManager::getInstance().getDefault(
                "MainWindow", "minimumSize", Dimension{50, 50}));

            setSize(UIManager::getInstance().getDefault(
                "MainWindow", "size", Dimension{300, 200}));
        }

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
            addSizeChangedListener(
                [this](clsn::core::ValueChangedEvent<Dimension>& e)
                {
                    auto& newValue = e.getNewValue();
                    m_control.setSize(newValue);
                    m_impl.repaint();
                });
        }
    };
}