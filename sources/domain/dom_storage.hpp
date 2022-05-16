#ifndef STORAGE_H
#define STORAGE_H

#include <map>

#include "dom_math.hpp"
#include "dom_string.hpp"
#include "dom_type.hpp"

namespace dom
{
	template <typename T> 
	class Storage
	{
	public:
		Storage()
		{
			// if (decltype(T) == decltype(sf::Font))
			// {
			// 	mFonts[dom::Math::getHash(STANDART_FONT_PATH)] = new sf::Font();
    		// 	mFonts.begin()->second->loadFromFile(STANDART_FONT_PATH);
			// }
		}
        ~Storage(){}

		const T& getCell(auto& aFontName)
		{
			return getCell(getId(aFontName));
		}

		const T& getCell(uint_64 aId)
		{
			return *(mStorage.find(aId)->second);
		}

		uint_64 getId(auto& arg)
		{
			uint_64 hash = dom::Math::getHash(arg);
			if (mStorage.count(hash) == 0)
			{
				auto it = mStorage.insert({hash,  new T(arg)});
			}
			return hash;
		}

		private:
			std::map<uint_64, T*> mStorage;
	};
}

#endif // !STORAGE_H