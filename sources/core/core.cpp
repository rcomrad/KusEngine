#include "core.hpp"

#include "event/event_manager.hpp"
#include "file/path.hpp"
#include "gui/gui.hpp"

#include "program_state.hpp"
#include "variable_storage.hpp"

core::Core::Core() noexcept
{
    // makeState(ProgramState::Name::Menu);

    auto& paths = file::Path::getInstance();
    // paths.setPath("resources", paths.getPath("main").value() +
    // +"resources/"); paths.setPath("textures",
    // paths.getPath("resources").value() + "textures/");
    paths.setDefault(paths.getPath("main").value() + "resources/");

    core::ProgramState::getInstance().reset(
        VariableStorage::getInstance().getWord("first_state"));
}

void
core::Core::run() noexcept
{
    gui::GUI gui;
    ProgramState& state = ProgramState::getInstance();
    // auto& em            = event::EventManager::getInstance();

    while (state.isAlive())
    {
        state.draw(gui);
        // em.update();
        state.interact();
    }
}

// void
// core::Core::makeState(ProgramState::Name aName) noexcept
// {
//     switch (aName)
//     {
//         // case ProgramState::Name::Game:
//         //     mCurrentState = std::make_unique<Game>();
//         //     break;
//         case ProgramState::Name::Menu:
//             mCurrentState = std::make_unique<Menu>();
//             break;
//     }
// }
