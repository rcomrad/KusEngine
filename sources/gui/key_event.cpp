#include "key_event.hpp"

gui::KeyEvent::KeyEvent(sf::Keyboard::Key aKey, bool aIsReleased) :
	Event(aIsReleased ? Event::EventType::KEY_RELEASED :
		Event::EventType::KEY_PRESSED),
	mKey	(KeyType(sint_8(aKey)))
{}

gui::KeyEvent::~KeyEvent() {}

gui::KeyEvent::KeyType
gui::KeyEvent::getKey() const
{
	return mKey;
}
