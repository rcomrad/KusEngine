#ifndef PLAYER_H
#define PLAYER_H

#include "gui/path.hpp"
#include "gui/mouse_event.hpp"

#include "space/spaceship.hpp"

//#define PLAYER_TEXTURE_PATH TEXTURES + "player.png"s
#define PLAYER_TEXTURE_PATH TEXTURES + "plain.png"s

namespace sr
{
	class Player : public Spaceship
	{
	public:
		virtual ~Player() = default;
		static std::shared_ptr<sr::Player> create(str_const_ref aTexturePath = PLAYER_TEXTURE_PATH);
		std::optional<uint_16> processEvent(gui::Event* aEvent) override;

	private:
		Player(str_const_ref aTexturePath);
	};
}

#endif // !PLAYER_H