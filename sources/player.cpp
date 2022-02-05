#include "player.hpp"

//Player::Player(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
Player::Player(std::string aTexturePath) :
	Spaceship(aTexturePath, 2)
{
	MyDrawable::setScale({ 0.35, 0.35 });
}
Player::~Player() {}

void
Player::processEvent(Event* aEvent)
{
	if (aEvent->getEventType() == Event::EventType::MOVE)
	{
		MoveEvent* me = static_cast <MoveEvent*> (aEvent);
		Spaceship::move(me->mCoord);
	}
}