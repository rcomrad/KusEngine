#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

//--------------------------------------------------------------------------------

#include "game/game_object.hpp"
#include "gui/gui_drawable.hpp"

namespace sr
{
	class SpaceObject : public GameObject, public gui::Drawable
	{
	public:
		SpaceObject(std::string aTexturePath, str_const_ref aLayer = "Default");
		virtual ~SpaceObject();
		virtual void move(dom::Pair<float> aCoord) = 0;
	};
}

//--------------------------------------------------------------------------------

#endif // !SPACE_OBJECT_HPP