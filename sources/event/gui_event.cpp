#include "gui_event.hpp"

event::GUIEvent::operator event::KeyEvent() const noexcept
{
    return {value, isPressed};
}

event::GUIEvent::operator event::MouseEvent() const noexcept
{
    return {x, y, isPressed, isLeft};
}

event::GUIEvent::operator event::GazeEvent() const noexcept
{
    return {x, y};
}
