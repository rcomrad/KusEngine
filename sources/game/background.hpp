#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gui/drawable.hpp"
#include "gui/path.hpp"

namespace sr
{
	class Background : public gui::Drawable
	{
	public:
		virtual ~Background() = default;
		static std::shared_ptr<sr::Background> create(std::string aTexturePath = BACKGROUND_TEXTURE_PATH);

	private:
		Background(std::string aTexturePath);
	};
}

#endif // !BACKGROUND_H