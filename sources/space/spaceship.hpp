#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "space_object.hpp"

namespace sr
{
	class Spaceship : public sr::SpaceObject
	{
	public:
		static std::shared_ptr<sr::Spaceship> create
		(
			std::string aTexturePath, 
			str_const_ref aLayer = "Default"
		);
		void create();
		virtual ~Spaceship() = default;
		virtual void move(dom::Pair<float> aCoord);
		virtual void update(float adTime);

	protected:
		Spaceship(std::string aTexturePath, str_const_ref aLayer);

	private:
		uint_16 mSpeed;
		dom::Pair<float> mTargetCoord;
	};
}

#endif // !SPACESHIP_H