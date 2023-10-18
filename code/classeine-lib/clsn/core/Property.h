#pragma once


namespace clsn::core
{
    template <typename T>
    class Property final
    {
    public:
        template <typename TString, typename TValue>
        Property(TString&& name, TValue&& initialValue)
        : m_name{std::forward<TString>(name)}
        , m_value{std::forward<TValue>(initialValue)}
        {
        }

        template <typename TString>
        Property(TString&& name)
        : m_name{std::forward<TString>(name)}
        {
        }

        const std::string& getName() const noexcept
        {
            return m_name;
        }

        const T& get() const noexcept
        {
            return m_value;
        }

        template <typename TValue>
        void set(TValue&& value)
        {
            m_value = std::forward<TValue>(value);
        }

    private:
        std::string m_name;
        T m_value;
    };
}