#include "logic_object.hpp"

#include "log_objects_storage.hpp"

lgc::LogicObject::LogicObject(std::vector<tag_type>& aTags)
{
    mTags = lgc::ObjecStorage::globalObjecStorage.addObject(this, aTags);
}

lgc::LogicObject::LogicObject()
{
    lgc::ObjecStorage::globalObjecStorage.removeObject(this, mTags);
}