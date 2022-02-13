#ifndef CLOSE_EVENT_HPP
#define CLOSE_EVENT_HPP

//--------------------------------------------------------------------------------

#include "core/domain.hpp"
#include "events/event.hpp"

namespace sr
{
	struct CloseEvent : public sr::Event
	{
		CloseEvent();
		virtual ~CloseEvent();
	};
}

//--------------------------------------------------------------------------------

#endif // !CLOSE_EVENT_HPP