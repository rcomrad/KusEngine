#include "gui_event.hpp"

event::GUIEvent::operator event::KeyEvent() const noexcept
{
    return {value, actionType};
}

event::GUIEvent::operator event::MouseEvent() const noexcept
{
    return {
        {x, y},
        actionType, MouseEvent::Button(value)
    };
}
