#include "core.hpp"

#include "gui/gui.hpp"

#include "menu.hpp"

core::Core::Core() noexcept
{
    makeState(ProgramState::Name::Menu);
}

void
core::Core::run() noexcept
{
    gui::GUI gui;

    while (true)
    {
        auto state = mCurrentState->getNewState();
        if (state == ProgramState::Name::Close) break;

        if (state != ProgramState::Name::Nun) makeState(state);

        gui.draw();
        gui.update();
    }
}

void
core::Core::makeState(ProgramState::Name aName) noexcept
{
    switch (aName)
    {
        // case ProgramState::Name::Game:
        //     mCurrentState = std::make_unique<Game>();
        //     break;
        case ProgramState::Name::Menu:
            mCurrentState = std::make_unique<Menu>();
            break;
    }
}
