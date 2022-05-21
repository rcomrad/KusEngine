#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "space_object.hpp"

namespace sr
{
	class Spaceship : public sr::SpaceObject
	{
	public:
		//Spaceship(std::string aTexturePath, sf::RenderWindow& aWindow);
		Spaceship(std::string aTexturePath, str_const_ref aLayer = "Default");
		virtual ~Spaceship();
		virtual void move(dom::Pair<float> aCoord);
		virtual void update(float adTime);

	private:
		uint_16 mSpeed;
		dom::Pair<float> mTargetCoord;
	};
}

#endif // !SPACESHIP_H