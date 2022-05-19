#ifndef LOGIC_OBJECT
#define LOGIC_OBJECT

#include <vector>

#include "domain/dom_string.hpp"

#include "gui/gui_event.hpp"

#include "basic_object.hpp"
#include "logic_types.hpp"

namespace lgc
{
    class LogicObject : virtual public BasicObject
    {
	public:
		LogicObject();
		virtual ~LogicObject() = default;
		virtual void processEvent(gui::Event* aEvent) = 0;
		virtual void update() = 0;

	private:
		std::vector<tag_type> mTags;
    };
}

#endif // !LOGIC_OBJECT