#include "events/close_event.hpp"

sr::CloseEvent::CloseEvent() :
	Event(CLOSE)
{}

sr::CloseEvent::~CloseEvent() {}