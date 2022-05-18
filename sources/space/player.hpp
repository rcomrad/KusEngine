#ifndef PLAYER_H
#define PLAYER_H

#include "gui/gui_paths.hpp"
#include "gui/gui_mouse_event.hpp"

#include "space/spaceship.hpp"

#define PLAYER_TEXTURE_PATH TEXTURES + "player.png"s

namespace sr
{
	class Player : public Spaceship
	{
	public:
		//Player(std::string aTexturePath, sf::RenderWindow& aWindow);
		Player(str_const_ref aTexturePath = PLAYER_TEXTURE_PATH);
		virtual ~Player();
		virtual void processEvent(gui::Event* aEvent);

	private:
	};
}

#endif // !PLAYER_H