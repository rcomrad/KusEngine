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
			std::string		aTexturePath, 
			std::string		aFontPath
		);

		DrawableAndWritable
		(
			std::string		aTexturePath
		);
		// DrawableAndWritable
		// (
		// 	std::string		aTexturePath	, 
		// 	std::string		aFontPath		, 
		// 	str_const_ref	aLayerName		= "Default",
		// 	str_const_ref	aViewName		= "Default"
		// );
		virtual ~DrawableAndWritable();
		void draw();
	};
}

#endif // !DRAWABLE_AND_WRITABLE_H