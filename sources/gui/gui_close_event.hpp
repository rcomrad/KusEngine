#ifndef CLOSE_EVENT_HPP
#define CLOSE_EVENT_HPP

//--------------------------------------------------------------------------------

#include "gui_event.hpp"

namespace gui
{
	struct CloseEvent : public Event
	{
		CloseEvent();
		virtual ~CloseEvent();
	};
}

//--------------------------------------------------------------------------------

#endif // !CLOSE_EVENT_HPP