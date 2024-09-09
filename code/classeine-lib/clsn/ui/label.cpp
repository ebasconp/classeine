#include "label.h"

#include "renderers/label_renderer.h"

namespace clsn::ui
{
    label::label()
    : control{"label"}
    , m_horizontal_alignment{clsn::draw::text_horizontal_alignment::left}
    , m_vertical_alignment{clsn::draw::text_vertical_alignment::middle}
    {
    }

    auto label::make_default_renderer() const -> std::unique_ptr<renderer_base>
    {
        return std::make_unique<renderers::label_renderer>();
    }

    auto label::get_horizontal_alignment() const -> clsn::draw::text_horizontal_alignment
    {
        return m_horizontal_alignment;
    }

    auto label::get_vertical_alignment() const -> clsn::draw::text_vertical_alignment
    {
        return m_vertical_alignment;
    }

    void label::set_horizontal_alignment(clsn::draw::text_horizontal_alignment horizontal_alignment)
    {
        m_horizontal_alignment = horizontal_alignment;
    }

    void label::set_vertical_alignment(clsn::draw::text_vertical_alignment vertical_alignment)
    {
        m_vertical_alignment = vertical_alignment;
    }
}