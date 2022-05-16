#ifndef LOGIC_OBJECT
#define LOGIC_OBJECT

namespace log
{
    class LogicObject
    {
	public:
		LogicObject();
		virtual ~LogicObject();
		virtual void processEvent(Event* aEvent) = 0;
		virtual void update() = 0;
    }
}

#endif // !LOGIC_OBJECT