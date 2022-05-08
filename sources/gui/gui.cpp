#include "gui/gui.hpp"

//--------------------------------------------------------------------------------

#define HEXAGON_DX                  0.f
#define HEXAGON_DY                  50.f

#define HEXAGON_SIZE                25.f
#define HEXAGON_OTLINE_THICKNESS    5.f

#define FONT_PATH                   "font.ttf"

#define TEXT_DX                     -18.f
#define TEXT_DY                     -20.f
#define TEXT_SINGLE_DX              10.f

sr::GUI::GUI(sint_16 aN, sint_16 aM) 
{
    mHotkeys[sf::Keyboard::Space] = KeyEvent::KeyEventType::SPACE_PAUSE;
}

bool
sr::GUI::isAppClosed() const
{
    return !gui::Window::isOpen();
}

std::vector<sr::Event*>
sr::GUI::getEvents()
{
    std::vector<Event*> result;
    sf::Event event;
    while (gui::Window::pollEvent(event))
    {
        
        switch (event.type)
        {
        case sf::Event::Closed:
            gui::Window::close();
            result.push_back(new CloseEvent());
            break;
        case sf::Event::MouseButtonReleased:
            result.push_back(new MoveEvent(
                sf::Mouse::getPosition(gui::Window::allWindow).x,
                sf::Mouse::getPosition(gui::Window::allWindow).y)
            );
            break;
        case sf::Event::KeyReleased:
            for (auto& i : mHotkeys)
            {
                if (i.first == event.key.code)
                {
                    result.push_back(new KeyEvent(i.second));
                    break;
                }
            }
            break;
        }
    }
    return result;
}

void 
sr::GUI::drawObjects
(
    const SetDrawebleType* aDrawableObjects
)
{
    gui::Window::clear();
    
    for (void* drawTarget : *aDrawableObjects) ((gui::GuiOutputBase*) drawTarget)->draw();

    gui::Window::display();
}

//--------------------------------------------------------------------------------
