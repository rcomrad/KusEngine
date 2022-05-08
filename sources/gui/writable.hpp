#ifndef WRITABLE_H
#define WRITABLE_H

#include "domain/dom_pair.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_storage.hpp"

#include "window.hpp"
#include "gui_output_base.hpp"

//#define STANDART_FONT_PATH "font.ttf"

namespace gui
{
	class Writable : virtual public GuiOutputBase
	{
	public:
		Writable(uint_8 aLayer = 0);
		Writable(str_const_ref aFontPath, uint_8 aLayer = 0);
		virtual ~Writable();

		void draw();

		dom::Pair<float> getPosition();
		void move(dom::Pair<float> aCoord);
		void resetPosition(dom::Pair<float> aCoord);
		void setScale(dom::Pair<float> aCoord);

		void setText(std::string aText);

	private:
		struct FontCell{
			sf::Font val;
			FontCell(str_const_ref aName)
			{
				val.loadFromFile(aName);
			}
		};

		sf::Text mText;
		static dom::Storage<FontCell> mFontsStorage;
		dom::Pair<float> mCoordOffset;
	};
}

#endif // !WRITABLE_H