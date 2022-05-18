#ifndef EVN_MOUSE_EVENT_H
#define EVN_MOUSE_EVENT_H

//--------------------------------------------------------------------------------

#include "domain/dom_pair.hpp"

#include "gui_event.hpp"

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