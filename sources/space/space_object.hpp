#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

//--------------------------------------------------------------------------------

#include "logic/logic_object.hpp"
#include "gui/gui_drawable.hpp"

namespace sr
{
	class SpaceObject : public gui::Drawable, public lgc::LogicObject
	{
	public:
		SpaceObject(std::string aTexturePath, str_const_ref aLayer = "Default");
		virtual ~SpaceObject();
		virtual void move(dom::Pair<float> aCoord) = 0;
	};
}

//--------------------------------------------------------------------------------

#endif // !SPACE_OBJECT_HPP