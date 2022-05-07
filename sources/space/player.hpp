#ifndef PLAYER_H
#define PLAYER_H

#include "space/spaceship.hpp"

#define PLAYER_TEXTURE_PATH TEXTURES + "player.png"

namespace sr
{
	class Player : public Spaceship
	{
	public:
		//Player(std::string aTexturePath, sf::RenderWindow& aWindow);
		Player(std::string aTexturePath = PLAYER_TEXTURE_PATH);
		virtual ~Player();
		virtual void processEvent(sr::Event* aEvent);

	private:
	};
}

#endif // !PLAYER_H