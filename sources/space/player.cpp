#include "space/player.hpp"

sr::Player::Player(str_const_ref aTexturePath) :
	Spaceship(aTexturePath, "Player")
{
	setView("Player");
	addTag("Player");

	//setScale({ 0.35, 0.35 });
}

sr::Player::~Player() {}

std::optional<uint_16> 
sr::Player::processEvent(gui::Event* aEvent)
{
	if (aEvent->getEventType() == gui::Event::EventType::MOUSE_RELEASED)
	{
		gui::MouseEvent* me = static_cast <gui::MouseEvent*> (aEvent);
		Spaceship::move(me->mCoord);
		return 1;
	}
	return {};
}