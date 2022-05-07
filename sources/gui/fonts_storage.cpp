#include "fonts_storage.hpp"

#define STANDART_FONT_PATH FONTS  + "font.ttf"s

eng::FontsStorage::FontsStorage()
{
    mFonts[dom::Math::getHash(STANDART_FONT_PATH)] = new sf::Font();
    mFonts.begin()->second.loadFromFile(STANDART_FONT_PATH);
}

eng::FontsStorage::~FontsStorage()
{
    for(auto& i : mFonts) delete i.second;
}

int
eng::FontsStorage::getFontId(str_const_ref aFontName)
{
    uint_64 hash = dom::Math::getHash(STANDART_FONT_PATH);
    if (mFonts.count(hash) == 0)
    {
        auto it = mFonts.insert({hash,  new sf::Font()});
        it->second.loadFromFile(aFontName);
    }
}

const sf::Font&
eng::FontsStorage::getFont(uint_64 aFontId) const
{
    mFonts[aFontId];
    return *(mFonts[aFontId]);
}