#ifndef LOGIC_OBJECT
#define LOGIC_OBJECT

#include <vector>
#include <optional>

#include "domain/string.hpp"

#include "gui/event.hpp"

#include "basic_object.hpp"
#include "type.hpp"
#include "time.hpp"

namespace lgc
{
    class LogicObject : virtual public BasicObject
    {
	public:
		LogicObject() = default;
		virtual ~LogicObject() = default;
		void create();

		virtual std::optional<uint_16> processEvent(gui::Event* aEvent);
		virtual void update(float adTime) = 0;

	private:
		std::vector<tag_type> mTags;
    };
}

#endif // !LOGIC_OBJECT