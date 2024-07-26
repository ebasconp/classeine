#pragma once

#include "ListContainer.h"

namespace clsn::ui
{
    class DualContainer : public ListContainer<bool>
    {
        bool m_horizontal;

    public:
        DualContainer();

        auto isHorizontal() const -> bool;
        void setHorizontal(bool horizontal);


    protected:
        void checkIfValid(const bool& fill) const override;
    };
}