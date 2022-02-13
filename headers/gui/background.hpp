#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gui/drawable.hpp"

namespace sr
{
	class Background : public Drawable
	{
	public:
		//Background(std::string aTexturePath, sf::RenderWindow& aWindow);
		Background(std::string aTexturePath);
		virtual ~Background();

	private:
	};
}

#endif // !BACKGROUND_H