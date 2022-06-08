#ifndef EVN_MOUSE_EVENT_H
#define EVN_MOUSE_EVENT_H

//--------------------------------------------------------------------------------

#include "domain/pair.hpp"

#include "event.hpp"

namespace gui
{
	class MouseEvent : public Event
	{
    public:
		MouseEvent(float aX, float aY);
		virtual ~MouseEvent() = default;
		dom::Pair<float> getPosition();

    public:
		dom::Pair<float> mCoord;
	};
}

//--------------------------------------------------------------------------------

#endif // !EVN_MOUSE_EVENT_H