#include "Font.h"

namespace clsn::draw
{
    const std::string& Font::getName() const noexcept { return m_name; }

    int Font::getSize() const noexcept { return m_size; }
}