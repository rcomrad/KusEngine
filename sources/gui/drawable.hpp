#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "gui/window.hpp"
#include "core/domain.hpp"

#include "gui/gui_output_base.hpp"

namespace sr
{
	class Drawable : virtual public GuiOutputBase
	{
	public:
		Drawable(std::string aTexturePath, uint_8 aLayer = 0);
		virtual ~Drawable();
		void draw();
		bool operator<(const Drawable& aOther) const;


	protected:
		Pair<float> getPosition();

		void move(Pair<float> aCoord);
		void resetPosition(Pair<float> aCoord);
		void setScale(Pair<float> aCoord);

	private:
		sf::Texture mTexture;
		sf::Sprite mSprite;

		//uint_8 mLayer;
	};

	//struct DrawableComparator {
	//	bool operator() (Drawable* a, Drawable* b) const;
	//};
}

#endif // !DRAWABLE_H