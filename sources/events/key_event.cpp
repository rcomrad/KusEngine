#include "events/key_event.hpp"

evn::KeyEvent::KeyEvent(KeyEventType aType) :
	Event(KEY_PRESSED),
	mType(aType)
{}

evn::KeyEvent::~KeyEvent() {}