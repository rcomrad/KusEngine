#include "space/space_object.hpp"

sr::SpaceObject::SpaceObject
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	Drawable		(aTexturePath),
	GuiOutputBase	(aLayer)
{}

sr::SpaceObject::~SpaceObject() {}