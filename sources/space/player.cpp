#include "space/player.hpp"

//Player::Player(std::string aTexturePath, sf::RenderWindow& aWindow) :
//	Drawable(aTexturePath, aWindow)
sr::Player::Player(std::string aTexturePath) :
	Spaceship(aTexturePath, 2)
{
	Drawable::setScale({ 0.35, 0.35 });
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