#ifndef PLANET_HPP
#define PLANET_HPP

//--------------------------------------------------------------------------------

#include "space/space_object.hpp"

#include "gui/gui_paths.hpp"

namespace sr
{
	class Planet : public SpaceObject
	{
	public:
		static std::shared_ptr<Planet> create();
		virtual ~Planet() = default;
		virtual void update(float adTime);
		virtual void move(dom::Pair<float> aCoord);

	private:
		double r = 400;
		double x0 = 500;
		double y0 = 500;
		double a = 1;

		Planet();
	};
}

//--------------------------------------------------------------------------------

#endif // !SPACE_OBJECT_HPP