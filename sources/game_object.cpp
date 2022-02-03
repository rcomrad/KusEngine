#include "game_object.hpp"

GameObject::GameObject
(
	std::string aTexturePath, 
	uint_8 aLayer
) :
	MyDrawable(aTexturePath, aLayer)
{

}

GameObject::~GameObject() {}