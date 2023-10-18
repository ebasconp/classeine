#include "Dimension.h"

clsn::gfx::Dimension::Dimension(int width, int height)
: m_width{width}
, m_height{height}
{
}


int clsn::gfx::Dimension::getWidth() const noexcept
{
    return m_width;
}


int clsn::gfx::Dimension::getHeight() const noexcept
{
    return m_height;
}