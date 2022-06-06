#include "space/player.hpp"

sr::Player::Player(str_const_ref aTexturePath) :
	Spaceship(aTexturePath, "Player")
{
	setView("Player");
}

std::shared_ptr<sr::Player>
sr::Player::create(str_const_ref aTexturePath)
{
	std::shared_ptr<sr::Player> result (new Player(aTexturePath));
	result->addTag("Player");
	result->Spaceship::create();
	return result;
}

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