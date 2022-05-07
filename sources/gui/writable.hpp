#ifndef WRITABLE_H
#define WRITABLE_H

#include "gui/window.hpp"
#include "core/domain.hpp"

#include "gui/gui_output_base.hpp"

//#define STANDART_FONT_PATH "font.ttf"

namespace sr
{
	class Writable : public GuiOutputBase
	{
	public:

		//Drawable(std::string aTexturePath, sf::RenderWindow& aWindow);
		//Writable(uint_8 aLayer = 0, std::string aFontPath = STANDART_FONT_PATH);
		Writable(uint_8 aLayer = 0);
		virtual ~Writable();
		//virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
		void draw();

	protected:
		Pair<float> getPosition();

		void moveText(Pair<float> aCoord);
		void resetTextPosition(Pair<float> aCoord);
		void setScale(Pair<float> aCoord);

		void setText(std::string aText);

	private:
		static sf::Font* allFont;
		sf::Text mText;

		Pair<int> mCoordOffset;
	};
}

#endif // !WRITABLE_H