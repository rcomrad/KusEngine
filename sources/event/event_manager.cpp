#include "event_manager.hpp"

#include "gui/window.hpp"

#include "event.hpp"

event::EventManager::EventManager() noexcept
    : mEvents(int(event::Event::Type::Last) + 1)
{
}

event::EventManager&
event::EventManager::getInstance() noexcept
{
    static EventManager instance;
    return instance;
}

void
event::EventManager::update() noexcept
{
    auto guiEvents = gui::Window::getInstance().pollEvent();
    for (auto& event : guiEvents)
    {
        auto& cell = getCell(event.type);

        switch (event.type)
        {
            case GUIEvent::Type::Close:
                cell.emplace_back().name = "close";
                break;
        }
    }
}

std::optional<event::StateEvent>
event::EventManager::pollStateEvent() noexcept
{
    std::optional<StateEvent> result;

    auto& cell = mEvents[int(event::Event::Type::State)];
    if (!cell.empty())
    {
        result = std::move(cell.back());
        cell.pop_back();
    }

    return result;
}

std::vector<event::Event>&
event::EventManager::getCell(event::GUIEvent::Type aType) noexcept
{
    switch (aType)
    {
        case GUIEvent::Type::Close:
            return mEvents[int(event::Event::Type::State)];
            break;
    }
}
