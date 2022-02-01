#include "game.hpp"

Game::Game() 
{
	mObjects.insert(new Player(TEXTURES + "player.png"));
	mObjects.insert(new Background(TEXTURES + "background.png"));
}

Game::~Game() 
{
	for (auto i : mObjects) delete i;
}

void
Game::run(std::vector<Event*> aEvents)
{
	//for (auto i : aEvents) std::cout << i->getEventType();
	for (Event* i : aEvents)
	{
		if (i->getEventType() == Event::EventType::MOVE)
		{
			MoveEvent* me = static_cast <MoveEvent*> (i);
			std::cout << me->mCoord.x << " " << me->mCoord.y << "\n";
		}
	}
}

const std::set<MyDrawable*, DrawableComparator>*
Game::getPresentation() const
{
	return &mObjects;
}