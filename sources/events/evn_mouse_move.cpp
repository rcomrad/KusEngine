#include "evn_mouse_move.hpp"

evn::MoveEvent::MoveEvent(float aX, float aY) :
	Event		(EventType::MOUSE_MOVE),
    mCoord(aX, aY)
{}