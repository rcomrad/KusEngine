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


protected:
	void moveSprite(Pair<float> aCoord);
	void resetSprite(Pair<float> aCoord);
	void setScale(Pair<float> aCoord);
	Pair<float> getPosition();

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	uint_8 mLayer;
	Pair<int> mCoordOffset;
};

struct DrawableComparator {
	bool operator() (MyDrawable* a, MyDrawable* b) const;
};

#endif // !DRAWABLE_H