// This file belongs to the Classeine project
//
// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: © 2024 Ernesto Bascón Pantoja

#include <clsn/ui/Control.h>

#include <clsn/ui/IRenderer.h>
#include <clsn/ui/UIManager.h>
#include <clsn/ui/Window.h>

#include <clsn/ui/events/MouseClickEvent.h>
#include <clsn/ui/events/MouseMovedEvent.h>

#include <clsn/ui/renderers/NullRenderer.h>

#include <clsn/draw/Region.h>

namespace clsn::ui
{
    CLSN_CPP_PROPERTY(Control, ActualPosition, draw::Point)
    CLSN_CPP_PROPERTY(Control, ActualSize, draw::Dimension)

    CLSN_CPP_BOOL_PROPERTY(Control, Enabled)
    CLSN_CPP_BOOL_PROPERTY(Control, Visible)

    CLSN_CPP_PROPERTY(Control, PreferredSize, std::optional<clsn::draw::Dimension>)

    Control::Control(std::string_view sectionName)
    : m_defaultSectionName{sectionName}
    , m_invalidated{true}
    {
        initControlEvents();
    }

    Control::~Control() = default;

    void Control::paint(Graphics& Graphics, const draw::Region& Region) const
    {
        debugCount("paint");

        if (!isInvalidated())
            return;

        getRenderer().paint(Graphics, Region, *this);
    }

    void Control::notifyMouseClickEvent(events::MouseClickEvent& e)
    {
        processMouseClickEvent(e);
    }

    void Control::addMouseMovedListener(core::EventListener<events::MouseMovedEvent> Event)
    {
        m_mouse_moved_listeners.add(std::move(Event));
    }

    void Control::notifyMouseMovedEvent(events::MouseMovedEvent& e)
    {
        processMouseMovedEvent(e);
    }

    void Control::processMouseClickEvent(events::MouseClickEvent& e)
    {
        if (!isEnabled())
            return;

        if (e.getStatus() == events::MouseClickStatus::released)
        {
            invokeInParentWindow([](auto& w) { w.releaseMouse(); });
        }

        m_mouse_click_listeners.notify(e);
    }

    void Control::processMouseMovedEvent(events::MouseMovedEvent& e)
    {
        if (!isEnabled())
            return;

        m_mouse_moved_listeners.notify(e);
    }

    void Control::addMouseClickListener(core::EventListener<events::MouseClickEvent> Event)
    {
        m_mouse_click_listeners.add(std::move(Event));
    }

    auto Control::getDefaultSectionName() const -> std::string_view
    {
        return m_defaultSectionName;
    }

    void Control::setRenderer(std::unique_ptr<IRenderer>&& renderer) const
    {
        m_renderer = std::move(renderer);
    }

    void Control::doLayout()
    {
        debugCount("doLayout");
    }

    void Control::invalidate() const noexcept { m_invalidated = true; }

    void Control::validate() const noexcept { m_invalidated = false; }

    auto Control::isInvalidated() const noexcept -> bool
    {
        return m_invalidated;
    }

    void Control::releaseMouse()
    {
        // Nothing to do here
    }

    auto Control::operator==(const Control& other) const -> bool
    {
        return this == &other;
    }


    auto Control::operator!=(const Control& other) const -> bool
    {
        return this != &other;
    }


    void Control::initControlEvents()
    {
        auto invalidate_proc = [this](auto&) { invalidate(); };

        addVisibleChangedListener(invalidate_proc);
    }

    void Control::setParentWindow(core::OptionalReference<Window> parentWindow)
    {
        m_parentWindow = parentWindow;
    }

    core::OptionalReference<Window> Control::getParentWindow()
    {
        return m_parentWindow;
    }

    core::constOptionalReference<Window>
        Control::getParentWindow() const
    {
        return m_parentWindow.to_const();
    }

    auto Control::containsPoint(const draw::Point& Point) const -> bool
    {
        return draw::Region{m_propertyActualPosition.get(), m_propertyActualSize.get()}.containsPoint(Point);
    }

    auto Control::getControlByPosition(const draw::Point& Point) const
        -> core::constOptionalReference<Control>
    {
        if (this->containsPoint(Point))
            return *this;

        return std::nullopt;
    }

    auto Control::isHovered() const -> bool
    {
        if (!m_parentWindow.hasValue())
            return false;

        return m_parentWindow.getRef().isHovered(*this);
    }


    auto Control::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::NullRenderer>();
    }

    auto Control::getRenderer() -> IRenderer&
    {
        if (m_renderer == nullptr)
            m_renderer = std::move(makeDefaultRenderer());

        return *m_renderer;
    }

    auto Control::getRenderer() const -> const IRenderer&
    {
        if (m_renderer == nullptr)
            m_renderer = std::move(makeDefaultRenderer());

        return *m_renderer;
    }

    void Control::loadDefaults()
    {
        // Do nothing here
    }

    auto Control::getActualPreferredSize() const -> const draw::Dimension&
    {
        const auto& size = getPreferredSize();
        if (size.has_value())
            return size.value();

        return UIManager::get_instance().getDimension(m_defaultSectionName, "preferredSize");
    }

    auto Control::getActualBounds() const -> draw::Region
    {
        return { getActualPosition(), getActualSize() };
    }

    void Control::setParentControl(core::OptionalReference<Control> ctrl)
    {
        m_parentControl = ctrl;
    }

    auto Control::getParentControl() -> core::OptionalReference<Control>
    {
        return m_parentControl;
    }

    auto Control::getParentControl() const -> core::constOptionalReference<Control>
    {
        return m_parentControl.to_const();
    }

    auto Control::toString() const -> std::string
    {
        using namespace clsn::core;
        return Strings::format("({}): {}", typeid(*this).name(), this);
    }
}