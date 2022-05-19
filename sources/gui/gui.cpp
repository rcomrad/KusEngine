#include "gui/gui.hpp"

//--------------------------------------------------------------------------------

// #define HEXAGON_DX                  0.f
// #define HEXAGON_DY                  50.f

// #define HEXAGON_SIZE                25.f
// #define HEXAGON_OTLINE_THICKNESS    5.f

// #define FONT_PATH                   "font.ttf"

// #define TEXT_DX                     -18.f
// #define TEXT_DY                     -20.f
// #define TEXT_SINGLE_DX              10.f

DraweblesSet gui::GUI::mDrawebles;

gui::GUI::GUI() 
{
   // mHotkeys[sf::Keyboard::Space] = KeyEvent::KeyEventType::SPACE_PAUSE;

    gui::GuiOutputBase::addLayer({
        {"Player", 100},
        {"Background", 1},
        {"Planet", 5},
        {"Data", 16}
    });
}

std::vector<gui::Event*>
gui::GUI::getEvents()
{
    std::vector<gui::Event*> result;
    sf::Event event;
    while (gui::Window::globalWindow.mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            result.push_back(makeCloseEvent(&event));
            break;
        case sf::Event::MouseButtonReleased:
            result.push_back(makeMouseEvent(&event));
            break;
        case sf::Event::KeyReleased:
            result.push_back(makeKeyEvent(&event));
            break;
        }
    }
    return result;
}

#include <space/player.hpp>

void 
gui::GUI::drawObjects
(
   // const SetDrawebleType* aDrawableObjects
)
{
    gui::Window::globalWindow.clear();
    gui::Window::globalWindow.centrateView("Player", (*(--mDrawebles.end()))->getPosition());
    for (auto drawTarget : mDrawebles) drawTarget->draw();
    //gui::Window::globalWindow.centrateView("Player", (*(--aDrawableObjects->end()))->getPosition());
    //for (auto drawTarget : *aDrawableObjects) drawTarget->draw();
    gui::Window::globalWindow.mWindow.display();
   
    // for (auto drawTarget : *aDrawableObjects) ((gui::GuiOutputBase*) drawTarget)->draw();

 
    //gui::Window::display();

    // gui::WindoVectorguiw::globalWindow.mWindow.setView(gui::Window::globalWindow.mWindow.getDefaultView());

    // (*(array.begin()))->draw();
    // (*(array.begin() + 3))->draw();


	// sf::View view;

    // gui::GuiOutputBase* ggg = (*(++ ++ array.begin()));
    // Player* pp = dynamic_cast<Player*> (ggg);
    // view.setCenter(pp->getCoord());
    // std::cout << "  ->  " << pp->getCoord().x << " " << pp->getCoord().y << "\n";

    // gui::Window::globalWindow.mWindow.setView(view);
    // (*(array.begin() + 1))->draw(); 
    //(*(array.begin() + 2))->draw();
    //

}

void 
gui::GUI::addDrawable(gui::GuiOutputBase* aDrawable)
{
    mDrawebles.insert(aDrawable);
}

void 
gui::GUI::removeDrawable(gui::GuiOutputBase* aDrawable)
{
    mDrawebles.erase(aDrawable);
}

gui::CloseEvent* 
gui::GUI::makeCloseEvent(sf::Event* aEvent)
{
    gui::CloseEvent* result = new gui::CloseEvent();
    gui::Window::globalWindow.mWindow.close();
    return result;
}

gui::MouseEvent* 
gui::GUI::makeMouseEvent(sf::Event* aEvent)
{
    sf::Vector2i pixelPos;
    sf::Vector2f worldPos;
    
    pixelPos = sf::Mouse::getPosition(gui::Window::globalWindow.mWindow);
    worldPos = gui::Window::globalWindow.mWindow.mapPixelToCoords(pixelPos);

    gui::MouseEvent* result = new gui::MouseEvent(worldPos.x, worldPos.y);
    return result;
}

gui::KeyEvent* 
gui::GUI::makeKeyEvent(sf::Event* aEvent)
{
    gui::KeyEvent* result = new gui::KeyEvent(aEvent->key.code);
    gui::Window::globalWindow.mWindow.close();
    return result;

    // for (auto& i : mHotkeys)
    // {
    //     if (i.first == event.key.code)
    //     {
    //         result.push_back(new KeyEvent(i.second));
    //         break;
    //     }
    // }
}

//--------------------------------------------------------------------------------
