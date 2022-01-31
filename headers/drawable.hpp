#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "window.h"
#include "domain.hpp"

class MyDrawable : public MyWindow
{
public:
	//Drawable(std::string aTexturePath, sf::RenderWindow& aWindow);
	MyDrawable(std::string aTexturePath);
	virtual ~MyDrawable();
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	void draw();

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;

	//sf::RenderWindow& mWindow;
};

#endif // !DRAWABLE_H