#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "domain/dom_paths.hpp"
#include "domain/dom_storage.hpp"

#include "gui_window.hpp"
#include "gui_output_base.hpp"

namespace gui
{
	class Drawable : virtual public GuiOutputBase
	{
	public:
		Drawable(std::string aTexturePath);

		virtual ~Drawable();
		void drawSprite();

		virtual sf_2f_val getSpritePosition();

		void moveSprite				(dom::Pair<float> aCoord);
		void resetSpritePosition	(dom::Pair<float> aCoord);
		void setSpriteScale			(dom::Pair<float> aCoord);

		void setRect(dom::Pair<int> aPosition, int aWidth, int aHeight);
		void setRectChange(int dX, int dY);

	private:
		struct TextureCell
		{
			sf::Texture val;
			TextureCell(str_const_ref aName)
			{
				val.loadFromFile(aName);
			}
		};
		static dom::Storage<TextureCell> mTextureStorage;

		sf::Sprite			mSprite;
		dom::Pair<int>	mPositionOffset;

		sf::IntRect mRect;
		dom::Pair<int>	mRectOffset;
		dom::Pair<uint_32>	mTextureSize;
		//flost mAnimationSpeed;
	};
}

#endif // !DRAWABLE_H