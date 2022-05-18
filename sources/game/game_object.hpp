#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "gui/gui_drawable.hpp"
#include "gui/gui_event.hpp"

namespace sr
{
	class GameObject //: public Drawable
	{
	public:
		//GameObject(std::string aTexturePath, uint_8 aLayer = 0);
		GameObject();
		virtual ~GameObject();
		virtual void processEvent(gui::Event* aEvent) = 0;
		virtual void update() = 0;
	};
}

#endif // !GAME_OBJECT_HPP