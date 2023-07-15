#include "parser.hpp"

#include <vector>

#include "file.hpp"

// file::Parser&
// file::Parser::getInstance() noexcept
// {
//     static Parser instance;
//     return instance;
// }

file::Variable
file::Parser::asVariable(const std::string& aStr) noexcept
{
    Variable result;
    int num = aStr.find('=');
    for (size_t i = 0; i < num; ++i)
    {
        if (std::islower(aStr[i]) || std::isupper(aStr[i]) || aStr[i] == '_')
        {
            result.name += aStr[i];
        }
    }
    // result.name      = aStr.substr(0, aStr.find(' '));
    result.value.str = aStr.substr(num + 2, aStr.size());

    normalize(result.name, Type::Lower);
    // normalize(result.value);

    // result.type = getTypeByValue(result.value);
    return result;
}

std::vector<std::unordered_map<std::string, file::Value>>
file::Parser::getAllObjects(const std::string& aFileName,
                            bool aIsCritical) noexcept
{
    auto lines = File::getLines(aFileName, aIsCritical);
    std::vector<std::unordered_map<std::string, Value>> result;
    std::unordered_map<std::string, Value> cur;
    for (auto& line : lines)
    {
        if (line == "}")
        {
            if (!cur.empty()) result.emplace_back(std::move(cur));
            cur.clear();
            continue;
        }
        else if (line == "{") continue;
        else if (line.empty()) continue;

        auto v      = asVariable(line);
        cur[v.name] = v.value;
    }
    return result;
}

std::vector<std::string>
file::Parser::slice(const std::string& aStr, char delimiter) noexcept
{
    std::vector<std::string> result(1);

    for (auto& i : aStr)
    {
        if (std::isalpha(i) || i == '_' || i == '~')
        {
            result.back().push_back(i);
        }
        if (i == ',')
        {
            result.emplace_back();
        }
    }

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

// std::unordered_map<std::string, std::string>
// file::Parser::asObject(const std::string& aStr) noexcept
// {
//     std::unordered_map<std::string, std::string> result;
//     for (auto& line : aStr)
//     {
//         result.emplace_back();
//         int indx = 0;
//         while (indx < line.size())
//         {
//             while (funk(line[indx])) indx++;
//             int from = indx;
//             while (!funk(line[indx])) indx++;
//             result.back().emplace_back(line.substr(from, indx - from));
//             indx += 1;
//         }
//     }
//     return result;
// }
