#ifndef DRAWABLE_AND_WRITABLE_H
#define DRAWABLE_AND_WRITABLE_H

#include "domain/dom_pair.hpp"

#include "gui_drawable.hpp"
#include "gui_writable.hpp"

namespace gui
{
	class DrawableAndWritable : public Drawable, public Writable
	{
	public:
		DrawableAndWritable
		(
			std::string		aTexturePath, 
			std::string		aFontPath
		);
		DrawableAndWritable
		(
			std::string		aTexturePath
		);
		virtual ~DrawableAndWritable() = default;

		void create();
	};
}

#endif // !DRAWABLE_AND_WRITABLE_H