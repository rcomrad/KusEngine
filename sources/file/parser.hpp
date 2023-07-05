#ifndef PARSER_HPP
#define PARSER_HPP

//--------------------------------------------------------------------------------

#include <optional>
#include <string>
#include <unordered_map>

namespace file
{
class Parser
{
public:
    static Parser& getInstance() noexcept;

    struct Variable
    {
        enum class Type
        {
            Nun,
            Int,
            Bool,
            String
        };

        Type type;
        std::string name;
        std::string value;
    };
    Variable asVariable(const std::string& aStr) const noexcept;

private:
    Parser() noexcept = default;

    enum class Type
    {
        Bub,
        Upper,
        Lower
    };
    static void normalize(std::string& aStr, Type aType = Type::Upper) noexcept;
    static Variable::Type getTypeByValue(std::string& aStr) noexcept;
};
} // namespace file

//--------------------------------------------------------------------------------

#endif // !PARSER_HPP
