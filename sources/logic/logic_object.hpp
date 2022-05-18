#ifndef LOGIC_OBJECT
#define LOGIC_OBJECT

#include "gui/gui_event.hpp"

#include "log_types.hpp"

namespace lgc
{
    class LogicObject
    {
	public:
		LogicObject(std::vector<tag_type>& aTags);
		virtual ~LogicObject();
		virtual void processEvent(gui::Event* aEvent) = 0;
		virtual void update() = 0;

	private:
		std::vector<tag_type> mTags;
    }
}

#endif // !LOGIC_OBJECT