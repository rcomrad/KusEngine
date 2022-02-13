#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP

//--------------------------------------------------------------------------------

#include "space/game_object.hpp"

namespace sr
{
	class SpaceObject : public GameObject
	{
	public:
		SpaceObject(std::string aTexturePath, uint_8 aLayer = 0);
		virtual ~SpaceObject();
		virtual void move(Pair<float> aCoord) = 0;
		virtual void update() = 0;

	};
}

//--------------------------------------------------------------------------------

#endif // !SPACE_OBJECT_HPP