#include "space_object.hpp"

SpaceObject::SpaceObject
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	GameObject(aTexturePath, aLayer)
{}

SpaceObject::~SpaceObject() {}