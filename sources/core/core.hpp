#ifndef CORE_HPP
#define CORE_HPP

//--------------------------------------------------------------------------------

#include "domain/holy_trinity.hpp"

namespace core
{
class Core
{
public:
    Core() noexcept;

    void run() noexcept;

private:
    // std::unique_ptr<ProgramState> mCurrentState;

    // void makeState(ProgramState::Name aName) noexcept;
};
} // namespace core

//--------------------------------------------------------------------------------

#endif // !CORE_HPP
