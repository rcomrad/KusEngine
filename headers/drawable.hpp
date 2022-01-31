#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "window.hpp"
#include "domain.hpp"

class MyDrawable : public MyWindow
{
public:
	//Drawable(std::string aTexturePath, sf::RenderWindow& aWindow);
	MyDrawable(std::string aTexturePath, uint_8 aLayer = 0);
	virtual ~MyDrawable();
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	void draw();
	bool operator<(const MyDrawable& aOther) const;

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	uint_8 mLayer;
};

struct DrawableComparator {
	bool operator() (MyDrawable* a, MyDrawable* b) const;
};

#endif // !DRAWABLE_H