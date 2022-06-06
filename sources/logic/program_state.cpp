#include "logic/program_state.hpp"

lgc::ProgramState::ProgramState() :
    mIsClosed   (false)
{}

lgc::ProgramState::~ProgramState()
{
    lgc::ObjectStorage::globalObjecStorage.clear();
}

void
lgc::ProgramState::close()
{
    mIsClosed = true;
}

bool
lgc::ProgramState::isClosed()
{
    return mIsClosed;
}

void
lgc::ProgramState::timeUpdate()
{
    float dTime = Time::globalTime.updateTime();
    // float dTime = Time::globalTime.getdTime();

    auto objects = ObjectStorage::globalObjecStorage["logical"];
    if (objects) 
    {
        for(auto& ptr : objects.value())
        {
            dynamic_cast<LogicObject*> (ptr.get())->update(dTime);

        }
    }
}