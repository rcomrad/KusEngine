#include "gui_mouse_event.hpp"

gui::MouseEvent::MouseEvent(float aX, float aY) :
	Event		(EventType::MOUSE_RELEASED),
    mCoord(aX, aY)
{}

dom::Pair<float> 
gui::MouseEvent::getPosition()
{
    return mCoord;
}