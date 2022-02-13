#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "drawable.hpp"
#include "event.hpp"

namespace sr
{
	class GameObject : public MyDrawable
	{
	public:
		GameObject(std::string aTexturePath, uint_8 aLayer = 0);
		virtual ~GameObject();
		virtual void processEvent(Event* aEvent) = 0;
	};
}

#endif // !GAME_OBJECT_HPP