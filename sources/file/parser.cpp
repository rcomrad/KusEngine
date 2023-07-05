#include "parser.hpp"

#include <vector>

file::Parser&
file::Parser::getInstance() noexcept
{
    static Parser instance;
    return instance;
}

file::Parser::Variable
file::Parser::asVariable(const std::string& aStr) const noexcept
{
    Variable result;
    result.name  = aStr.substr(0, aStr.find(' '));
    result.value = aStr.substr(aStr.find('=') + 2, aStr.size());

    normalize(result.name, Type::Lower);
    normalize(result.value);

    result.type = getTypeByValue(result.value);
    return result;
}

void
file::Parser::normalize(std::string& aStr, Type aType) noexcept
{
    if (aType == Type::Upper)
    {
        for (auto& i : aStr)
            if (std::islower(i)) i = std::toupper(i);
    }
    else if (aType == Type::Lower)
    {
        for (auto& i : aStr)
            if (std::isupper(i)) i = std::tolower(i);
    }
}

file::Parser::Variable::Type
file::Parser::getTypeByValue(std::string& aStr) noexcept
{
    Variable::Type result = Variable::Type::Nun;

    std::unordered_map<char, int> characters;
    for (auto& i : aStr)
    {
        if (std::isupper(i)) characters['U']++;
        else if (std::isdigit(i)) characters['D']++;
        else if (std::isdigit(i)) characters['O']++;
    }

    if (aStr == "YES" || aStr == "NO")
    {
        result = Variable::Type::Bool;
    }
    else if (characters['U'] == 0 && characters['O'] == 0)
    {
        result = Variable::Type::Int;
    }
    else
    {
        result = Variable::Type::String;
    }

    return result;
}
