#include "menu.hpp"

void
core::Menu::processEvents() noexcept
{
    // for (gui::Event* i : aEvents)
    // {
    //     switch (i->getEventType())
    //     {
    //         case gui::Event::EventType::MOUSE_RELEASED:
    //             mouseEventsHandler(i);
    //             break;
    //         case gui::Event::EventType::KEY_RELEASED:
    //             break;
    //         case gui::Event::EventType::WINDOW_CLOSED:
    //             close();
    //             break;
    //     }
    // }
}

void
core::Menu::update() noexcept
{
}

// void
// sr::Menu::mouseEventsHandler(gui::Event* aEvent)
// {
//     gui::MouseEvent* moveEvent = static_cast<gui::MouseEvent*>(aEvent);
//     std::cout << moveEvent->mCoord.x << " " << moveEvent->mCoord.y << "\n";

//     auto button = lgc::ObjectStorage::globalObjecStorage["Button"];
//     if (!button) return;

//     auto res =
//         (dynamic_cast<lgc::LogicObject*>((*button.value().begin()).get()))
//             ->processEvent(aEvent);
//     if (res)
//     {
//         switch (res.value())
//         {
//             case 0:
//                 mNextState = lgc::ProgramState::ProgramStateName::Game;
//                 break;
//         }
//     }
// }
