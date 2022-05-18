#include "log_objects_storage.hpp"

lgc::ObjecStorage lgc::ObjecStorage::globalObjecStorage;

tag_type
lgc::ObjecStorage::getTagNumber(str_const_ref aName) const
{
    return dom::Math::getHash(aName);
}

std::vector<tag_type>
lgc::ObjecStorage::addObject(LogicObject* aObject, std::vector<str_val> aTags)
{
    std::vector<tag_type> result;

    for(auto& i : aTags)
    {
        auto it = mTagDictionary.find(i);
        if (it == mTagDictionary.end())
        {
            //TODO: is it effective? 
            //mTagDictionary[i] = mTagDictionary.size();
            mTagDictionary[i] = getTagNumber(i);
            it = mTagDictionary.find(i);
        }

        //TODO: while? 
        if (mObjects.size() > it->second)
        {
            mObjects.push_back({});
        }

        mObjects[it->second].insert(aObject);
        result.emplace_back(it->second);
    }

    return result;
}

void
lgc::ObjecStorage::removeObject(LogicObject* aObject, std::vector<tag_type> aTags)
{
    for(auto& i : aTags)
    {
        mObjects[i].erase(aObject);
    }
}

std::set<lgc::LogicObject*>&
lgc::ObjecStorage::operator[](str_const_ref aTag)
{
    return mObjects[getTagNumber(aTag)];
}

const std::set<lgc::LogicObject*>&
lgc::ObjecStorage::operator[](str_const_ref aTag) const
{
    return mObjects[getTagNumber(aTag)];
}

std::set<lgc::LogicObject*>
lgc::ObjecStorage::operator[](std::vector<str_const_ref> aTag)
{
    std::set<lgc::LogicObject*> result = mObjects[getTagNumber(aTag.back())];
    for(auto& i : aTag)
    {
        auto& temp = mObjects[getTagNumber(aTag.back())];
        std::set_intersection
        (
            temp.begin(), temp.end(),
            result.begin(), result.end(),
            std::back_inserter(result)
        );
    }
    return result;
}
