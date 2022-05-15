#ifndef WRITABLE_H
#define WRITABLE_H

#include "domain/dom_pair.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_storage.hpp"

#include "window.hpp"
#include "gui_output_base.hpp"
#include "gui_paths.hpp"

//#define STANDART_FONT_PATH "font.ttf"

namespace gui
{
	class Writable : virtual public GuiOutputBase
	{
	public:
		 Writable(std::string aFontPath = STANDART_FONT_PATH);
		// Writable		
		// (
		// 	str_const_ref	aLayerName		= "Default",
		// 	str_const_ref	aViewName		= "Default"
		// );
		// Writable
		// (
		// 	std::string		aFontPath		, 
		// 	str_const_ref	aLayerName		= "Default",
		// 	str_const_ref	aViewName		= "Default"
		// );
		virtual ~Writable();

		void draw();

		void move			(dom::Pair<float> aCoord);
		void resetPosition	(dom::Pair<float> aCoord);
		void setScale		(dom::Pair<float> aCoord);
		
		virtual sf_2f_val getTextPosition();

		void setText		(std::string aText);

	private:
		struct FontCell
		{
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