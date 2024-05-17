#pragma once

#include <string>
#include <utility>

namespace clsn::draw
{
    class Font
    {
        std::string m_name;
        int m_size;

    public:
        template <typename StringType>
        Font(StringType&& name, int size)
        : m_name{std::forward<StringType>(name)}
        , m_size{size}
        {
        }

        const std::string& getName() const noexcept;
        int getSize() const noexcept;
    };
}