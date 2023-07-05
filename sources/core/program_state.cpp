#include "program_state.hpp"

core::ProgramState::ProgramState() noexcept
{
    setNewState(ProgramState::Name::Nun);
}

core::ProgramState::~ProgramState() noexcept
{
}

core::ProgramState::Name
core::ProgramState::getNewState() noexcept
{
    return mNewState;
}

void
core::ProgramState::close() noexcept
{
    setNewState(ProgramState::Name::Close);
}

void
core::ProgramState::setNewState(ProgramState::Name aStateName) noexcept
{
    mNewState = aStateName;
}

// void
// lgc::ProgramState::timeUpdate()
// {
//     float dTime = Time::globalTime.updateTime();
//     // float dTime = Time::globalTime.getdTime();

//     auto objects = ObjectStorage::globalObjecStorage["logical"];
//     if (objects)
//     {
//         for (auto& ptr : objects.value())
//         {
//             dynamic_cast<LogicObject*>(ptr.get())->update(dTime);
//         }
//     }
// }
