#include "gui.hpp"

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

GUI::GUI(sint_16 aN, sint_16 aM) //:
    //s(cmp = [](int a, int b) { return a < b; })
    //mDrawableObjects([](MyDrawable* a, MyDrawable* b) { return a < b; })
    //mWindow     (sf::VideoMode(aN, aM), "Evolution"),
{


    mDrawableObjects.insert(new Player(TEXTURES + "player.png"));
    mDrawableObjects.insert(new Background(TEXTURES + "background.png"));
}

bool
GUI::isAppClosed() const
{
    return !mWindow.isOpen();
}

std::vector<GUI::EventType>
GUI::getEvents()
{
    std::vector<EventType> result;
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();

        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Key::Tab     :
                result.push_back(GUI::EventType::SWITCH_DRAW_MODE);
                break;
            case sf::Keyboard::Key::Space   :
                result.push_back(GUI::EventType::SWITCH_PAUSE);
                break;
            case sf::Keyboard::Key::X       :
                result.push_back(GUI::EventType::INCREASE_SPEED);
                break;
            case sf::Keyboard::Key::Z       :
                result.push_back(GUI::EventType::DECREASE_SPEED);
                break;
            case sf::Keyboard::Key::LShift  :
                result.push_back(GUI::EventType::STANDART_PAUSE);
                break;
            default:
                break;
            }
        }
    }
    return result;
}

void 
GUI::drawField()
{
    mWindow.clear(sf::Color::Black);

    //Drawable d(TEXTURES + "1.png", mWindow);
    //d.draw();
    //mWindow.draw(cartoon);
    
    for (MyDrawable* drawTarget : mDrawableObjects) drawTarget->draw();

    mWindow.display();
}

//--------------------------------------------------------------------------------
