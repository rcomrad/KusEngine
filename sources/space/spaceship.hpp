#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "space_object.hpp"
#include "core/my_time.hpp"

namespace sr
{
	class Spaceship : public sr::SpaceObject
	{
	public:
		//Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow);
		Spaceship(std::string aTexturePath, uint_8 aLayer = 0);
		virtual ~Spaceship();
		virtual void move(dom::Pair<float> aCoord);
		virtual void update();

	private:
		uint_16 mSpeed;
		dom::Pair<float> mTargetCoord;
	};
}

#endif // !SPACESHIP_H