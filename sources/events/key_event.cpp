#include "events/key_event.hpp"

sr::KeyEvent::KeyEvent(KeyEventType aType) :
	Event(KEY_PRESSED),
	mType(aType)
{}

sr::KeyEvent::~KeyEvent() {}