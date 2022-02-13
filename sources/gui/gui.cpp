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

//#define SHOW_CELLS_COORDINATES

sr::GUI::GUI(sint_16 aN, sint_16 aM) //:
    //s(cmp = [](int a, int b) { return a < b; })
    //mDrawableObjects([](MyDrawable* a, MyDrawable* b) { return a < b; })
    //mWindow     (sf::VideoMode(aN, aM), "Evolution"),
{
    mHotkeys[sf::Keyboard::Space] = KeyEvent::KeyEventType::SPACE_PAUSE;

    //mDrawableObjects.insert(new Player(TEXTURES + "player.png"));
    //mDrawableObjects.insert(new Background(TEXTURES + "background.png"));
}

bool
sr::GUI::isAppClosed() const
{
    return !Window::allWindow.isOpen();
}

std::vector<sr::Event*>
sr::GUI::getEvents()
{
    std::vector<Event*> result;
    sf::Event event;
    while (Window::allWindow.pollEvent(event))
    {
        
        switch (event.type)
        {
        case sf::Event::Closed:
            Window::allWindow.close();
            result.push_back(new CloseEvent());
            break;
        case sf::Event::MouseButtonReleased:
            result.push_back(new MoveEvent(
                sf::Mouse::getPosition(Window::allWindow).x,
                sf::Mouse::getPosition(Window::allWindow).y)
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
    const
    std::set<Drawable*, DrawableComparator>*
    aDrawableObjects
)
{
    Window::allWindow.clear(sf::Color::Black);

    //Drawable d(TEXTURES + "1.png", mWindow);
    //d.draw();
    //mWindow.draw(cartoon);
    
    for (Drawable* drawTarget : *aDrawableObjects) drawTarget->draw();

    Window::allWindow.display();
}

//--------------------------------------------------------------------------------
