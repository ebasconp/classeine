#include <clsn/ui/ContentPane.h>

#include <clsn/ui/renderers/ContentPaneRenderer.h>

namespace clsn::ui
{
    using namespace clsn::core;
    using namespace clsn::draw;

    ContentPane::ContentPane(std::string_view sectionName)
    : PaintableControl{sectionName}
    {
        initContentPaneEvents();
    }

    void ContentPane::initContentPaneEvents()
    {
        addActualSizeChangedListener([this](auto& )
        {
            doLayout();
        });
    }

    void ContentPane::doLayout()
    {
        auto control_optional_ref = getActualInnerControl();
        if (!control_optional_ref.hasValue())
            return;

        auto& inner_control_value = control_optional_ref.getRef();
        inner_control_value.setActualPosition(this->getActualPosition());
        inner_control_value.setActualSize(this->getActualSize());
        inner_control_value.doLayout();
    }

    auto ContentPane::makeDefaultRenderer() const -> std::unique_ptr<IRenderer>
    {
        return std::make_unique<renderers::ContentPaneRenderer>();
    }

    void ContentPane::invalidate() const noexcept
    {
        Control::invalidate();

        if (getActualInnerControl().hasValue())
            getActualInnerControl().getRef().invalidate();
    }

    void ContentPane::validate() const noexcept
    {
        Control::validate();

        if (getActualInnerControl().hasValue())
            getActualInnerControl().getRef().validate();
    }

    auto ContentPane::isInvalidated() const noexcept -> bool
    {
        if (!getActualInnerControl().hasValue())
        {
            return Control::isInvalidated();
        }

        return getActualInnerControl().getRef().isInvalidated();
    }

    void ContentPane::processMouseClickEvent(events::MouseClickEvent& e)
    {
        auto control_optional_ref = getActualInnerControl();
        if (!control_optional_ref.hasValue())
            return;

        auto& inner_control = control_optional_ref.getRef();
        if (!inner_control.isVisible() || !inner_control.isEnabled())
            return;

        if (inner_control.containsPoint(e.getPoint()))
        {
            inner_control.notifyMouseClickEvent(e);
        }

        Control::processMouseClickEvent(e);
    }

    void ContentPane::processMouseMovedEvent(events::MouseMovedEvent& e)
    {
        Control::processMouseMovedEvent(e);

        auto control_optional_ref = getActualInnerControl();
        if (!control_optional_ref.hasValue())
            return;

        auto& inner_control = control_optional_ref.getRef();
        if (!inner_control.isVisible() || !inner_control.isEnabled())
            return;

        if (inner_control.containsPoint(e.getPosition()))
        {
            inner_control.notifyMouseMovedEvent(e);
        }
    }

    auto ContentPane::getControlByPosition(const Point &Point) const
            -> constOptionalReference<Control>
    {
        auto control_optional_ref = getActualInnerControl();

        if (!control_optional_ref.hasValue())
            return {};

        auto& inner_control = control_optional_ref.getRef();
        if (!inner_control.isVisible() || !inner_control.isEnabled())
            return {};

        return inner_control.getControlByPosition(Point);
    }
}