#include "program_state.hpp"

#include "event/event_manager.hpp"
#include "file/path.hpp"

core::ProgramState::ProgramState() noexcept : mIsAlive(true)
{
    // setNewState(ProgramState::Name::Nun);
    mAllStates = file::Path::getAllContentPathsMap(
        file::Path::getInstance().getPath("states").value());
    for (auto& i : mAllStates) i.second += '/';

    // reset(VariableStorage::getInstance().getWord("first_state"));
}

core::ProgramState&
core::ProgramState::getInstance() noexcept
{
    static ProgramState instance;
    return instance;
}

// core::ProgramState::~ProgramState() noexcept
// {
// }

// core::ProgramState::Name
// core::ProgramState::getNewState() noexcept
// {
//     return mNewState;
// }

// void
// core::ProgramState::close() noexcept
// {
//     setNewState(ProgramState::Name::Close);
// }

// void
// core::ProgramState::setNewState(ProgramState::Name aStateName) noexcept
// {
//     mNewState = aStateName;
// }

void
core::ProgramState::draw(gui::GUI& gui) noexcept
{
    gui.draw(mScenes);
}

void
core::ProgramState::interact() noexcept
{
    // static auto& em = event::EventManager::getInstance();
    // em.update();

    // auto newState = em.pollStateEvent();
    // if (newState.has_value())
    // {
    //     reset(newState.value().name);
    // }

    auto guiEvents = gui::Window::getInstance().pollEvent();
    for (const auto& event : guiEvents)
    {
        // auto& cell = getCell(event.type);

        switch (event.type)
        {
            case event::GUIEvent::Type::Close:
                // cell.emplace_back().name = "close";
                reset("close");
                break;
            case event::GUIEvent::Type::MouseInput:
                for (auto& i : mScenes)
                {
                    if (i.interact(event::MouseEvent(event))) break;
                }
                break;
        }
    }
}

bool
core::ProgramState::isAlive() const noexcept
{
    return mIsAlive;
}

// std::unordered_map<std::string, std::string>
// core::ProgramState::loadStates() noexcept
// {
//     return file::Path::getAllContentPathsMap(
//         file::Path::getInstance().getPath("states").value());
// }

void
core::ProgramState::reset(const std::string& aStateName) noexcept
{
    auto it = mAllStates.find(aStateName);
    if (it != mAllStates.end())
    {
        loadState(it->second);
    }
    else if (aStateName == "close")
    {
        mIsAlive = false;
        mScenes.clear();
    }
}

void
core::ProgramState::loadState(const std::string& aPath) noexcept
{
    mScenes.clear();
    auto scenes = file::Path::getAllContentPaths(aPath + "scenes/");
    for (auto& i : scenes)
    {
        mScenes.emplace_back(i);
    }
}

// void
// lgc::ProgramState::timeUpdate()
// {
//     float dTime = Time::globalTime.updateTime();
//     // float dTime = Time::globalTime.getdTime();

//     auto objects = ObjectStorage::globalObjecStorage["logical"];
//     if (objects)
//     {
//         for (auto& ptr : objects.value())
//         {
//             dynamic_cast<LogicObject*>(ptr.get())->update(dTime);
//         }
//     }
// }
