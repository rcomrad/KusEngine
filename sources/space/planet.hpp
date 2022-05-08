#ifndef PLANET_HPP
#define PLANET_HPP

//--------------------------------------------------------------------------------

#include "space/space_object.hpp"
#include "core/my_time.hpp"

#include "gui/gui_paths.hpp"

namespace sr
{
	class Planet : public SpaceObject
	{
	public:
		Planet();
		virtual ~Planet();
		virtual void processEvent(Event* aEvent);
		virtual void update();
		virtual void move(dom::Pair<float> aCoord);


		double r = 400;
		double x0 = 500;
		double y0 = 500;
		double a = 1;
	};
}

//--------------------------------------------------------------------------------

#endif // !SPACE_OBJECT_HPP