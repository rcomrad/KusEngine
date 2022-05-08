#include "space/player.hpp"

sr::Player::Player(str_const_ref aTexturePath) :
	Spaceship(aTexturePath, 10),
	GuiOutputBase(10)
{
	setScale({ 0.35, 0.35 });
}

sr::Player::~Player() {}

void
sr::Player::processEvent(Event* aEvent)
{
	if (aEvent->getEventType() == Event::EventType::MOVE)
	{
		MoveEvent* me = static_cast <MoveEvent*> (aEvent);
		Spaceship::move(me->mCoord);
	}
}