#ifndef GUI_EVENT_HPP
#define GUI_EVENT_HPP

//--------------------------------------------------------------------------------

namespace event
{

struct KeyEvent
{
public:
    int key;
    bool isPressed = false;
};

struct MouseEvent
{
public:
    float x, y;
    bool isPressed;
    bool isLeft;
};

struct GazeEvent
{
public:
    float x, y;
};

struct GUIEvent
{
public:
    enum class Type
    {
        Nun,
        Close,
        KeyInput,
        MouseInput,
        Gaze
    };

    GUIEvent::Type type = GUIEvent::Type::Nun;

    int value = 0;
    float x = 0, y = 0;
    bool isPressed = false;
    bool isLeft    = false;

    operator KeyEvent() const noexcept;
    operator MouseEvent() const noexcept;
    operator GazeEvent() const noexcept;
};

} // namespace event

//--------------------------------------------------------------------------------

#endif // !GUI_EVENT_HPP
