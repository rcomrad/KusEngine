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