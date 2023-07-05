#ifndef MENU_HPP
#define MENU_HPP

//--------------------------------------------------------------------------------

#include "program_state.hpp"

namespace core
{
class Menu : public ProgramState
{
public:
    Menu() noexcept= default;
    virtual ~Menu() noexcept = default;

    virtual void processEvents() noexcept final;
    virtual void update() noexcept final;

private:
    // void mouseEventsHandler(gui::Event* aEvent);
};
} // namespace core

//--------------------------------------------------------------------------------

#endif // !MENU_HPP
