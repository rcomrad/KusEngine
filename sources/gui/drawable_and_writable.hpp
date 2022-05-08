#ifndef DRAWABLE_AND_WRITABLE_H
#define DRAWABLE_AND_WRITABLE_H

#include "domain/dom_pair.hpp"

#include "drawable.hpp"
#include "writable.hpp"

namespace gui
{
	class DrawableAndWritable : public Drawable, public Writable
	{
	public:
		DrawableAndWritable
		(
			std::string aTexturePath, 
			std::string aFontPath, 
			uint_8 aLayer = 0
		);
		virtual ~DrawableAndWritable();
		void draw();
	};
}

#endif // !DRAWABLE_AND_WRITABLE_H