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
		Drawable(std::string aTexturePath);
		// Drawable
		// (
		// 	std::string		aTexturePath	, 
		// 	str_const_ref	aLayerName		= "Default",
		// 	str_const_ref	aViewName		= "Default"
		// );
		virtual ~Drawable();
		void draw();

		virtual sf_2f_val getSpritePosition();

		void move			(dom::Pair<float> aCoord);
		void resetPosition	(dom::Pair<float> aCoord);
		void setScale		(dom::Pair<float> aCoord);

		auto getCoord()
		{
			return mSprite.getPosition();
		}

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
		dom::Pair<float>	mCoordOffset;
	};
}

#endif // !DRAWABLE_H