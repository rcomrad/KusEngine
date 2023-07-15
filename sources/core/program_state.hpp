#ifndef PROGRAM_STATE_HPP
#define PROGRAM_STATE_HPP

#include <unordered_map>

#include "gui/gui.hpp"
#include "logic/scene.hpp"

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
    void interact() noexcept;

    bool isAlive() const noexcept;

    void reset(const std::string& aStateName) noexcept;

    // protected:
    //     void close() noexcept;
    //     void setNewState(Name aStateName) noexcept;

private:
    // Name mNewState;
    ProgramState() noexcept;
    bool mIsAlive;
    std::vector<lgc::Scene> mScenes;

    std::unordered_map<std::string, std::string> mAllStates;
    // static std::unordered_map<std::string, std::string> loadStates()
    // noexcept;

    void loadState(const std::string& aPath) noexcept;
};
} // namespace core

#endif // !PROGRAM_STATE_HPP
