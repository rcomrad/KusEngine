#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "drawable.hpp"

class Background : public MyDrawable
{
public:
	//Background(std::string aTexturePath, sf::RenderWindow& aWindow);
	Background(std::string aTexturePath);
	virtual ~Background();

private:
};

#endif // !BACKGROUND_H