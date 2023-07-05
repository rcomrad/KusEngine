#ifndef PROGRAM_STATE_HPP
#define PROGRAM_STATE_HPP

namespace core
{
class ProgramState
{
public:
    enum class Name
    {
        Nun,
        Close,
        Menu,
        Game
    };

    ProgramState() noexcept;
    virtual ~ProgramState() noexcept;

    virtual void processEvents() noexcept = 0;
    virtual void update() noexcept        = 0;
    Name getNewState() noexcept;

protected:
    void close() noexcept;
    void setNewState(Name aStateName) noexcept;

private:
    Name mNewState;
};
} // namespace core

#endif // !PROGRAM_STATE_HPP
