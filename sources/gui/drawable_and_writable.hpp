#ifndef DRAWABLE_AND_WRITABLE_H
#define DRAWABLE_AND_WRITABLE_H

#include "gui/drawable.hpp"
#include "gui/writable.hpp"

namespace sr
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

	protected:
		Pair<float> getPosition();

		void move(Pair<float> aCoord);
		void resetPosition(Pair<float> aCoord);
		void setScale(Pair<float> aCoord);

	private:
		Pair<int> mCoordOffset;
	};
}

#endif // !DRAWABLE_AND_WRITABLE_H