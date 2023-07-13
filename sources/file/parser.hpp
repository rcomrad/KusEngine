#ifndef PARSER_HPP
#define PARSER_HPP

//--------------------------------------------------------------------------------

#include <optional>
#include <string>
#include <unordered_map>

#include "variable.hpp"

namespace file
{
class Parser
{
public:
    // static Parser& getInstance() noexcept;

    static Variable asVariable(const std::string& aStr) noexcept;

    static std::vector<std::unordered_map<std::string, Value>> getAllObjects(
        const std::string& aFileName, bool aIsCritical = false) noexcept;

private:
    Parser() noexcept = default;

    enum class Type
    {
        Bub,
        Upper,
        Lower
    };
    static void normalize(std::string& aStr, Type aType = Type::Upper) noexcept;

    // std::unordered_map<std::string, std::string> asObject(
    //     const std::string& aStr) noexcept;
};
} // namespace file

//--------------------------------------------------------------------------------

#endif // !PARSER_HPP
