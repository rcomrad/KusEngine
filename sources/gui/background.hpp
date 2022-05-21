#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gui/gui_drawable.hpp"
#include "gui/gui_paths.hpp"

namespace sr
{
	class Background : public gui::Drawable
	{
	public:
		Background(std::string aTexturePath = BACKGROUND_TEXTURE_PATH);
		virtual ~Background();

	private:
	};
}

#endif // !BACKGROUND_H