#ifndef GUI_EVENT_HPP
#define GUI_EVENT_HPP

//--------------------------------------------------------------------------------

#include "domain/pair.hpp"

namespace event
{

enum class ActionType
{
    Nun,
    Pressed,
    Relised,
    Gaze
};

struct KeyEvent
{
public:
    int key;
    ActionType type;
};

struct MouseEvent
{
public:
    enum class Button
    {
        Nun,
        Left,
        Right
    };

    dom::Pair<float> coord;
    ActionType type;
    Button button;
};

struct GUIEvent
{
public:
    // union Data
    // {

    //     int value;
    //     struct
    //     {
    //         float x, y;
    //     };
    // };

public:
    enum class Type
    {
        Nun,
        Close,
        KeyInput,
        MouseInput,
    };

    GUIEvent::Type type   = GUIEvent::Type::Nun;
    ActionType actionType = ActionType::Nun;
    // Data eventData;
    int value = 0;
    float x, y;

    operator KeyEvent() const noexcept;
    operator MouseEvent() const noexcept;
};

} // namespace event

//--------------------------------------------------------------------------------

#endif // !GUI_EVENT_HPP
