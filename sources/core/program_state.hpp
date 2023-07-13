#ifndef PROGRAM_STATE_HPP
#define PROGRAM_STATE_HPP

#include <unordered_map>

#include "gui/gui.hpp"
#include "gui/scene.hpp"

namespace core
{
class ProgramState
{
public:
    // enum class Name
    // {
    //     Nun,
    //     Close,
    //     Menu,
    //     Game
    // };

    // ~ProgramState() = default;

    // void processEvents() noexcept = 0;
    // void update() noexcept        = 0;
    // Name getNewState() noexcept;

    static ProgramState& getInstance() noexcept;

    void draw(gui::GUI& gui) noexcept;

    bool isAlive() const noexcept;

    // protected:
    //     void close() noexcept;
    //     void setNewState(Name aStateName) noexcept;

private:
    // Name mNewState;
    ProgramState() noexcept;
    bool mIsAlive;
    std::vector<gui::Scene> mScenes;

    std::unordered_map<std::string, std::string> mAllStates;
    // static std::unordered_map<std::string, std::string> loadStates()
    // noexcept;

    void reset(const std::string& aStateName) noexcept;
    void loadState(const std::string& aPath) noexcept;
};
} // namespace core

#endif // !PROGRAM_STATE_HPP
