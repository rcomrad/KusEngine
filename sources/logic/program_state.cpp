#include "logic/program_state.hpp"

lgc::ProgramState::ProgramState() :
    mIsClosed   (false)
{}

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

    std::set<lgc::BasicObject*> objects = ObjectStorage::globalObjecStorage["logical"];
    for(auto ptr : objects)
    {
        dynamic_cast<LogicObject*> (ptr)->update(dTime);

    }
}