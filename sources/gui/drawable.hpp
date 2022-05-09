#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "domain/dom_paths.hpp"
#include "domain/dom_storage.hpp"

#include "window.hpp"

#include "gui/gui_output_base.hpp"

namespace gui
{
	class Drawable : virtual public GuiOutputBase
	{
	public:
		Drawable(std::string aTexturePath, uint_8 aLayer = 0);
		virtual ~Drawable();
		void draw();

		dom::Pair<float> getPosition();

		void move(dom::Pair<float> aCoord);
		void resetPosition(dom::Pair<float> aCoord);
		void setScale(dom::Pair<float> aCoord);

	private:
		struct TextureCell{
			sf::Texture val;
			TextureCell(str_const_ref aName)
			{
				val.loadFromFile(aName);
			}
		};

		static dom::Storage<TextureCell> mTextureStorage;
		sf::Sprite mSprite;
		sf::Texture ttf;
		dom::Pair<float> mCoordOffset;
	};
}

#endif // !DRAWABLE_H