#include "objects_storage.hpp"

lgc::ObjectStorage lgc::ObjectStorage::globalObjecStorage;
std::map<uint_64, tag_type> lgc::ObjectStorage::mTagDictionary;
std::vector<std::set<lgc::BasicObject*>> lgc::ObjectStorage::mObjects;

uint_64
lgc::ObjectStorage::getTagNumber(str_const_ref aName) const
{
    return dom::Math::getHash(aName);
}

std::set<tag_type>
lgc::ObjectStorage::addObject(lgc::BasicObject* aObject, std::vector<str_val> aTags)
{
    std::set<tag_type> result;

    for(auto& i : aTags)
    {
        uint_64 hashNum = getTagNumber(i);
        auto it = mTagDictionary.find(hashNum);
        if (it == mTagDictionary.end())
        {
            //TODO: is it effective? 
            //mTagDictionary[i] = mTagDictionary.size();
            mTagDictionary[hashNum] = mObjects.size();
            mObjects.resize(mObjects.size() + 1);
            it = mTagDictionary.find(hashNum);
        }

        mObjects[it->second].insert(aObject);
        result.insert(it->second);
    }

    return result;
}

void
lgc::ObjectStorage::removeObject(lgc::BasicObject* aObject, std::set<tag_type> aTags)
{
    for(auto& i : aTags)
    {
        mObjects[i].erase(aObject);
    }
}

std::set<lgc::BasicObject*>&
lgc::ObjectStorage::operator[](str_const_ref aTag)
{
    return mObjects[mTagDictionary[getTagNumber(aTag)]];
}

const std::set<lgc::BasicObject*>&
lgc::ObjectStorage::operator[](str_const_ref aTag) const
{
    return mObjects[mTagDictionary[getTagNumber(aTag)]];
}

std::set<lgc::BasicObject*>
lgc::ObjectStorage::operator[](std::vector<str_val> aTag)
{
    uint_64 tagNum = mTagDictionary[getTagNumber(aTag.back())];
    std::set<lgc::BasicObject*> result = mObjects[tagNum];
    for(auto i : aTag)
    {
        auto temp = mObjects[tagNum];
        std::set_intersection
        (
            temp.begin(), temp.end(),
            result.begin(), result.end(),
            std::inserter(result, result.begin())
        );
    }
    return result;
}
