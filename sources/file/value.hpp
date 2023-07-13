
#ifndef VALUE_HPP
#define VALUE_HPP

#include <string>

#include "domain/pair.hpp"

namespace file
{
struct Value
{
    enum class Type
    {
        Nun,
        Int,
        Bool,
        String
    };

    std::string str;

    operator int() const noexcept;
    operator float() const noexcept;
    operator bool() const noexcept;

    operator std::string() const noexcept;

    operator dom::Pair<float>() const noexcept;

    Type getType() const noexcept;
};
} // namespace file

#endif // !VALUE_HPP
