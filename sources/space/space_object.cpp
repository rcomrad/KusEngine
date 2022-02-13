#include "space/space_object.hpp"

sr::SpaceObject::SpaceObject
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	GameObject(aTexturePath, aLayer)
{}

sr::SpaceObject::~SpaceObject() {}