#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gui/drawable.hpp"
#include "game/game_object.hpp"

namespace sr
{
	class Background : public GameObject, public Drawable
	{
	public:
		//Background(std::string aTexturePath, sf::RenderWindow& aWindow);
		Background(std::string aTexturePath);
		virtual ~Background();
		virtual void update();
		virtual void processEvent(Event* aEvent);

	private:
	};
}

#endif // !BACKGROUND_H