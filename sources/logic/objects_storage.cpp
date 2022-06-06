#include "objects_storage.hpp"

lgc::ObjectStorage lgc::ObjectStorage::globalObjecStorage;

lgc::ObjectStorage::ObjectStorage()
{
    clear();
}

uint_64
lgc::ObjectStorage::getTagNumber(str_const_ref aName) const
{
    return dom::Math::getHash(aName);
}

std::set<tag_type>
lgc::ObjectStorage::addObject(std::shared_ptr<lgc::BasicObject> aObject, std::vector<str_val> aTags)
{
    std::set<tag_type> result;

    for(auto& i : aTags)
    {
        gui::GuiOutputBase;
        tag_type tag = prepareStorage(i);
        mObjects[tag]->insert(aObject);
        if (tag == 0)
        {
            mDrawables.insert(dynamic_cast<gui::GuiOutputBase*>(aObject.get()));
        }
        result.insert(tag);
    }

    return result;
}

void
lgc::ObjectStorage::removeObject(std::shared_ptr<lgc::BasicObject> aObject, std::set<tag_type> aTags)
{
    for(auto& i : aTags)
    {
        if(i >= mObjects.size()) continue;
        auto it = mObjects[i]->find(aObject);
        if(it != mObjects[i]->end())
        {
            mObjects[i]->erase(it);
        }
    }
}

void 
lgc::ObjectStorage::clear()
{
    mTagDictionary.clear();
    mObjects.clear();
    #ifdef _DBG_
    mStringDictionary.clear();
    #endif
    mDrawables.clear();
   
    prepareStorage(DRAWABLE_TAG);

mObjects.push_back
(
std::shared_ptr<std::set<std::shared_ptr<BasicObject>>> 
(new std::set<std::shared_ptr<BasicObject>>)
);
}

std::optional<std::set<std::shared_ptr<lgc::BasicObject>>&>
lgc::ObjectStorage::operator[](str_const_ref aTag)
{
    #ifdef _DBG_
    if (mTagDictionary.count(getTagNumber(aTag)) == 0) 
    {
        dom::ErrorMessages::writeError("there_is_no_object_with_given_tag", "given_tag:", aTag);
        return *mObjects[1];
    }
    #endif
    return *mObjects[mTagDictionary[getTagNumber(aTag)]];
}

const std::optional<std::set<std::shared_ptr<lgc::BasicObject>>&>
lgc::ObjectStorage::operator[](str_const_ref aTag) const
{
    auto it1 = mTagDictionary.find(getTagNumber(aTag));
    if (it1 == mTagDictionary.end()) 
    {
        #ifdef _DBG_
        dom::ErrorMessages::writeError("there_is_no_object_with_given_tag", "given_tag:", aTag);
        #endif
        //TODO: optional
        return {*mObjects[1]};
    }

    return  *mObjects[it1->second];
}

std::set<std::shared_ptr<lgc::BasicObject>>
lgc::ObjectStorage::operator[](std::vector<str_val> aTag)
{
    uint_64 tagNum = mTagDictionary[getTagNumber(aTag.back())];
    std::set<std::shared_ptr<lgc::BasicObject>> result = *mObjects[tagNum];
    for(auto i : aTag)
    {
        auto temp = mObjects[tagNum];
        std::set_intersection
        (
            temp->begin(), temp->end(),
            result.begin(), result.end(),
            std::inserter(result, result.begin())
        );
    }
    return result;
}

const gui::DraweblesSet&
lgc::ObjectStorage::getSortedDrawables() const
{
    return mDrawables;
}

tag_type
lgc::ObjectStorage::prepareStorage(str_const_ref aStr)
{
    uint_64 hashNum = getTagNumber(aStr);
    auto it = mTagDictionary.find(hashNum);
    if (it == mTagDictionary.end())
    {
        #ifdef _DBG_
        mStringDictionary[aStr] = hashNum;
        #endif      
        //TODO: is it effective? 
        //mTagDictionary[i] = mTagDictionary.size();
        mTagDictionary[hashNum] = mObjects.size();
        //mObjects.resize(mObjects.size() + 1);
        mObjects.push_back
        (
            std::shared_ptr<std::set<std::shared_ptr<BasicObject>>> 
            (new std::set<std::shared_ptr<BasicObject>>)
        );
        it = mTagDictionary.find(hashNum);
    }
    return  it->second;
}