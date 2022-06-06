#include "basic_object.hpp"

#include "objects_storage.hpp"

void
lgc::BasicObject::clearFromStorage()
{
   ObjectStorage::globalObjecStorage.removeObject(shared_from_this(), mTags);
}

void
lgc::BasicObject::addTag(str_const_ref aTag)
{
    std::vector<str_val> temp {aTag};
    addTag(temp);
}

void
lgc::BasicObject::addTag(std::vector<str_val> aTags)
{
   auto temp = ObjectStorage::globalObjecStorage.addObject(shared_from_this(), aTags);
   mTags.insert(temp.begin(), temp.end());
}