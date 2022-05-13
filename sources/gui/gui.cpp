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
        sf::Vector2i pixelPos;
        sf::Vector2f worldPos;
        switch (event.type)
        {
        case sf::Event::Closed:
            gui::Window::close();
            result.push_back(new CloseEvent());
            break;
        case sf::Event::MouseButtonReleased:
            pixelPos = sf::Mouse::getPosition(gui::Window::allWindow);
            worldPos = gui::Window::allWindow.mapPixelToCoords(pixelPos);

            // sf::View view;
            // gui::GuiOutputBase* ggg = (*(++ ++ array.begin()));
            // Player* pp = dynamic_cast<Player*> (ggg);
            // view.setCenter(pp->getCoord());

            result.push_back(new MoveEvent(
                // sf::Mouse::getPosition(gui::Window::allWindow).x,
                // sf::Mouse::getPosition(gui::Window::allWindow).y)
                worldPos.x, worldPos.y)
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

#include <space/player.hpp>

void 
sr::GUI::drawObjects
(
    const SetDrawebleType* aDrawableObjects
)
{
    gui::Window::clear();

    std::vector<gui::GuiOutputBase*> array;
    for (auto drawTarget : *aDrawableObjects) array.emplace_back(((gui::GuiOutputBase*) drawTarget));
    // for (auto drawTarget : *aDrawableObjects) ((gui::GuiOutputBase*) drawTarget)->draw();


    //gui::Window::display();

    gui::Window::allWindow.setView(gui::Window::allWindow.getDefaultView());

    (*(array.begin()))->draw();
    (*(++ ++ ++ array.begin()))->draw();


	sf::View view;

    gui::GuiOutputBase* ggg = (*(++ ++ array.begin()));
    Player* pp = dynamic_cast<Player*> (ggg);
    view.setCenter(pp->getCoord());
    std::cout << "  ->  " << pp->getCoord().x << " " << pp->getCoord().y << "\n";

    gui::Window::allWindow.setView(view);
    (*(++ array.begin()))->draw(); 
    (*(++ ++ array.begin()))->draw();
    //
 
    gui::Window::display();
}

//--------------------------------------------------------------------------------
