#ifndef PLAYER_H
#define PLAYER_H

#include "spaceship.hpp"

class Player : public Spaceship
{
public:
	//Player(std::string aTexturePath, sf::RenderWindow& aWindow);
	Player(std::string aTexturePath);
	virtual ~Player();
	virtual void processEvent(Event* aEvent);

private:
};

#endif // !PLAYER_H