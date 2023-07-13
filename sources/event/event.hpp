#ifndef EVENT_HPP
#define EVENT_HPP

//--------------------------------------------------------------------------------

#include <string>

namespace event
{

struct StateEvent
{
public:
    std::string name;
};

struct Event
{
public:
    enum class Type
    {
        Nun,
        State,
        Windows,
        First = Nun,
        Last  = Windows
    };

    Event::Type type = Event::Type::Nun;

    std::string name;

    operator StateEvent() const noexcept;
    // operator MouseEvent() const noexcept;
    // operator GazeEvent() const noexcept;
};

} // namespace event

//--------------------------------------------------------------------------------

#endif // !EVENT_HPP
