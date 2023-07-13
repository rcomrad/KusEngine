#include "value.hpp"

#include <unordered_map>

file::Value::operator int() const noexcept
{
    return std::stoi(str);
}

file::Value::operator float() const noexcept
{
    return std::stof(str);
}

file::Value::operator bool() const noexcept
{
    bool result = false;
    if (str == "on") result = true;
    return result;
}

file::Value::operator std::string() const noexcept
{
    return str;
}

file::Value::operator dom::Pair<float>() const noexcept
{
    dom::Pair<float> result;

    int cur = 0;
    std::string temp;
    bool flag = true;
    for (int cur = 0; cur < str.size() + 1; ++cur)
    {
        if (std::isdigit(str[cur]) || str[cur] == '.')
        {
            temp += str[cur];
        }
        else
        {
            if (temp.size())
            {
                if (flag)
                {
                    result.x = std::stof(temp);
                }
                else
                {
                    result.y = std::stof(temp);
                }
                temp.clear();
                flag = !flag;
            }
        }
    }

    return result;
}

file::Value::Type
file::Value::getType() const noexcept
{
    Value::Type result = Value::Type::Nun;

    std::unordered_map<char, int> characters;
    for (auto& i : str)
    {
        if (std::isupper(i)) characters['U']++;
        else if (std::islower(i)) characters['L']++;
        else if (std::isdigit(i)) characters['D']++;
        else characters['?']++;
    }

    if (str == "YES" || str == "NO")
    {
        result = Value::Type::Bool;
    }
    else if (characters['U'] == 0 && characters['L'] == 0 &&
             characters['?'] == 0)
    {
        result = Value::Type::Int;
    }
    else
    {
        result = Value::Type::String;
    }

    return result;
}
