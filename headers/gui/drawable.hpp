#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "gui/window.hpp"
#include "core/domain.hpp"

namespace sr
{
	class Drawable
	{
	public:
		//Drawable(std::string aTexturePath, sf::RenderWindow& aWindow);
		Drawable(std::string aTexturePath, uint_8 aLayer = 0);
		virtual ~Drawable();
		//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
		void draw();
		bool operator<(const Drawable& aOther) const;


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
		bool operator() (Drawable* a, Drawable* b) const;
	};
}

#endif // !DRAWABLE_H