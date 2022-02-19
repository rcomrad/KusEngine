#include "space/space_object.hpp"

sr::SpaceObject::SpaceObject
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	//GameObject(aTexturePath, aLayer)
	Drawable(aTexturePath, aLayer)
{}

sr::SpaceObject::~SpaceObject() {}