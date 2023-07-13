#include "event.hpp"

event::Event::operator event::StateEvent() const noexcept
{
    return {name};
}

// event::Event::operator MouseEvent() const noexcept
// {
//     return {x, y, isPressed, isLeft};
// }

// event::Event::operator GazeEvent() const noexcept
// {
//     return {x, y};
// }
