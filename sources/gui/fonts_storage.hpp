#ifndef FONTS_STORAGE_H
#define FONTS_STORAGE_H

#include <map>

#include <SFML/Graphics.hpp>

#include "domain/dom_math.hpp"
#include "domain/dom_string.hpp"
#include "domain/dom_type.hpp"

namespace eng
{
	class FontsStorage
	{
	public:
		FontsStorage();
        ~FontsStorage();

        int getFontId(str_const_ref aFontName);
        const sf::Font& getFont(uint_64 aFontId) const;

	private:
		std::map<uint_64, sf::Font*> mFonts;
	};
}

#endif // !FONTS_STORAGE_H