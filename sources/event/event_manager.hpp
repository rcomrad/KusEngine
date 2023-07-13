#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

//--------------------------------------------------------------------------------

#include <optional>
#include <vector>

#include "event.hpp"
#include "gui_event.hpp"

namespace event
{

class EventManager
{
public:
    static EventManager& getInstance() noexcept;

    void update() noexcept;

    std::optional<StateEvent> pollStateEvent() noexcept;

private:
    EventManager() noexcept;

    std::vector<std::vector<Event>> mEvents;

    std::vector<Event>& getCell(GUIEvent::Type aType) noexcept;
};
} // namespace event

//--------------------------------------------------------------------------------

#endif // !EVENT_MANAGER_HPP
