#include "objects_storage.hpp"

lgc::ObjectStorage lgc::ObjectStorage::globalObjecStorage;

lgc::ObjectStorage::ObjectStorage() : 
    mMutex (false)
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
        uint_64 hashNum = getTagNumber(i);
      	#ifdef _DBG_
		mStringDictionary[i] = hashNum;
	    #endif      
        auto it = mTagDictionary.find(hashNum);
        if (it == mTagDictionary.end())
        {
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

        mObjects[it->second]->insert(aObject);
        result.insert(it->second);
    }

    return result;
}

void
lgc::ObjectStorage::removeObject(std::shared_ptr<lgc::BasicObject> aObject, std::set<tag_type> aTags)
{
    if (mMutex) return;

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
    mMutex = true;

    mTagDictionary.clear();
    // for(auto& i : mObjects) 
    // {
    //     i.get()->clear();
    // }

    while(mObjects.size() > 0) 
    {
        mObjects.erase(mObjects.begin());
    }

    mObjects.clear();

    //TODO: optional
            mObjects.push_back
            (
                std::shared_ptr<std::set<std::shared_ptr<BasicObject>>> 
                (new std::set<std::shared_ptr<BasicObject>>)
            );

    mMutex = false;

    std::set<tag_type> tags =  addObject(nullptr, {DRAWABLE_TAG});
    removeObject(nullptr, tags);
    mDrawebleSet = mObjects[*(tags.begin())];
}

std::set<std::shared_ptr<lgc::BasicObject>>&
lgc::ObjectStorage::operator[](str_const_ref aTag)
{
    #ifdef _DBG_
    if (mTagDictionary.count(getTagNumber(aTag)) == 0) 
    {
        dom::ErrorMessages::writeError("there_is_no_object_with_given_tag", "given_tag:", aTag);
        return *mObjects[0];
    }
    #endif
    return *mObjects[mTagDictionary[getTagNumber(aTag)]];
}

const std::set<std::shared_ptr<lgc::BasicObject>>&
lgc::ObjectStorage::operator[](str_const_ref aTag) const
{
    auto it1 = mTagDictionary.find(getTagNumber(aTag));
    if (it1 == mTagDictionary.end()) 
    {
        #ifdef _DBG_
        dom::ErrorMessages::writeError("there_is_no_object_with_given_tag", "given_tag:", aTag);
        #endif
        //TODO: optional
        return {*mObjects[0]};
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

std::set<std::shared_ptr<lgc::BasicObject>>&
lgc::ObjectStorage::getDrawables()
{
    return *mDrawebleSet.get();
}