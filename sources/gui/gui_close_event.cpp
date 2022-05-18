#include "gui_close_event.hpp"

gui::CloseEvent::CloseEvent() :
	Event(Event::EventType::WINDOW_CLOSED)
{}

gui::CloseEvent::~CloseEvent() {}