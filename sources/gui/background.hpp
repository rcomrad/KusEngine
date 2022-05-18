#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gui/gui_drawable.hpp"
#include "gui/gui_paths.hpp"
#include "game/game_object.hpp"

namespace sr
{
	class Background : public GameObject, public gui::Drawable
	{
	public:
		Background(std::string aTexturePath = BACKGROUND_TEXTURE_PATH);
		virtual ~Background();
		virtual void update();
		virtual void processEvent(gui::Event* aEvent);

	private:
	};
}

#endif // !BACKGROUND_H