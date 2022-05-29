#ifndef WRITABLE_H
#define WRITABLE_H

#include "domain/dom_pair.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_storage.hpp"

#include "gui_window.hpp"
#include "gui_output_base.hpp"
#include "gui_paths.hpp"

namespace gui
{
	class Writable : virtual public GuiOutputBase
	{
	public:
		 Writable(std::string aFontPath = STANDART_FONT_PATH);

		virtual ~Writable();

		void drawText();

		void moveText			(dom::Pair<float> aCoord);
		void setTextPosition	(dom::Pair<float> aCoord);
		void resetTextPosition	(dom::Pair<float> aCoord);
		void setTextScale		(dom::Pair<float> aCoord);
		
		virtual sf_2f_val getTextPosition();

		void setText		(std::string aText);

	private:
		struct FontCell
		{
			public:
			sf::Font val;
			FontCell(str_const_ref aName)
			{
				val.loadFromFile(aName);
			}
		};
		static dom::Storage<FontCell> mFontsStorage;

		sf::Text			mText;
		dom::Pair<float>	mCoordOffset;
	};
}

#endif // !WRITABLE_H