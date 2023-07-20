#include "common_data.hpp"

#include <algorithm>
#include <iostream>

#include "parser.hpp"
#include "path.hpp"

file::CommonData::CommonData() noexcept
{
    auto& paths = file::Path::getInstance();

    auto commonPath = paths.getPath("common");
    if (!commonPath.has_value()) return;

    auto fileNames = paths.getAllContentPaths(commonPath.value());

    for (auto& path : fileNames)
    {
        auto from = path.rend() - std::find(path.rbegin(), path.rend(), '/');
        auto to   = path.rend() - std::find(path.rbegin(), path.rend(), '.');

        std::string objectsLabel = path.substr(from, to - from - 1);

        auto objects = file::Parser::getAllObjects(path);
        for (auto& object : objects)
        {
            auto it = object.find("name");
            if (it == object.end()) continue;

            mCommonStorage[objectsLabel][it->second] = std::move(object);
            mCommonStorage[objectsLabel][it->second].erase(it);
        }
    }
}

const file::CommonData&
file::CommonData::getInstance() noexcept
{
    static CommonData instance;
    return instance;
}

boost::optional<const file::VariableArray&>
file::CommonData::getData(const std::string& aObjectLabel,
                          const std::string& aObjectName) const noexcept
{
    boost::optional<const file::VariableArray&> result;

    auto it1 = mCommonStorage.find(aObjectLabel);
    if (it1 != mCommonStorage.end())
    {
        auto it2 = it1->second.find(aObjectName);
        if (it2 != it1->second.end())
        {
            result = it2->second;
        }
        else
        {
            std::cout << "No \"" << aObjectName << "\" object name found!"
                      << std::endl;
        }
    }
    else
    {
        std::cout << "No \"" << aObjectLabel << "\" label found!" << std::endl;
    }

    return result;
}

void
file::CommonData::addData(const std::string& aObjectLabel,
                          const std::string& aObjectName,
                          file::VariableArray& Variables) const noexcept
{
    auto data = getData(aObjectLabel, aObjectName);
    if (!data.has_value()) return;

    Variables.insert(data.value().begin(), data.value().end());
}
