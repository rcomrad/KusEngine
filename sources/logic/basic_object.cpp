#include "basic_object.hpp"

#include <functional>
#include <unordered_map>

#include "file/parser.hpp"
#include "file/path.hpp"

#include "functor_storage.hpp"

lgc::Object::Object(const file::VariableArray& aVariables)
    : GUIObject(file::Path::getInstance().getPath("texture").value() +
                std::string(aVariables.find("texture")->second))
{
    static std::unordered_map<std::string,
                              std::function<void(const file::Value& aVal)>>
        handler = {
            {"scale",    [&](const file::Value& aVal) { setScale(aVal); }     },
            {"position", [&](const file::Value& aVal) { setPosition(aVal); }  },
            {"ofset",    [&](const file::Value& aVal) { setOfset(aVal); }     },
            {"text",     [&](const file::Value& aVal)
             { setTexts(file::Parser::slice(aVal, ',')); }},
            {"on_click",
             [&](const file::Value& aVal) { setOnClickAction(aVal); }         }
    };

    for (const auto& i : aVariables)
    {
        auto it = handler.find(i.first);
        if (it != handler.end())
        {
            it->second(i.second);
        }
    }
}

bool
lgc::Object::interact(const event::MouseEvent& aEvent) noexcept
{
    static auto& funcStorage = FunctorStorage::getInstance();
    // if (aEvent.type != event::ActionType::Relised)
    bool result   = false;
    int intersect = contains(aEvent.coord);
    if (intersect != -1)
    {
        if (aEvent.type == event::ActionType::Relised)
        {
            if (!mOnClick.empty())
                funcStorage.executeFunctor(mOnClick[intersect]);
        }
        result = true;
    }
    return result;
}

void
lgc::Object::setOnClickAction(const std::string& aActionStr) noexcept
{
    static auto& fStorage = FunctorStorage::getInstance();

    auto actions = file::Parser::slice(aActionStr, ',');
    for (auto& i : actions)
    {
        mOnClick.emplace_back(fStorage.getFunctorID(i));
    }
}

// void
// lgc::BasicObject::addTag(str_const_ref aTag)
// {
//     std::vector<str_val> temp{aTag};
//     addTag(temp);
// }

// void
// lgc::BasicObject::addTag(std::vector<str_val> aTags)
// {
//     auto temp =
//         ObjectStorage::globalObjecStorage.addObject(shared_from_this(),
//         aTags);
//     mTags.insert(temp.begin(), temp.end());
// }
