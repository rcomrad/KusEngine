#ifndef PLAYER_H
#define PLAYER_H

#include "drawable.hpp"

class Player : public MyDrawable
{
public:
	//Player(std::string aTexturePath, sf::RenderWindow& aWindow);
	Player(std::string aTexturePath);
	virtual ~Player();

private:
};

#endif // !PLAYER_H