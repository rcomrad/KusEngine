#ifndef WRITABLE_H
#define WRITABLE_H

#include "gui/window.hpp"
#include "core/domain.hpp"

#include "gui/gui_output_base.hpp"

//#define STANDART_FONT_PATH "font.ttf"

namespace sr
{
	class Writable : virtual public GuiOutputBase
	{
	public:
		Writable(uint_8 aLayer = 0);
		Writable(std::string aFontPath, uint_8 aLayer = 0);
		virtual ~Writable();
		void draw();

	protected:
		Pair<float> getPosition();

		void move(Pair<float> aCoord);
		void resetPosition(Pair<float> aCoord);
		void setScale(Pair<float> aCoord);

		void setText(std::string aText);

	private:
		static std::vector<sf::Font*> allFont;
		sf::Text mText;

		Pair<int> mCoordOffset;
	};
}

#endif // !WRITABLE_H