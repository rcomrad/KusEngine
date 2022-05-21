#include "gui_window.hpp"

#define WINDOW_SIZE_X	700
#define WINDOW_SIZE_Y	700

#define _DBG_

gui::Window gui::Window::globalWindow;

//sf::RenderWindow gui::Window::allWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Evolution");

gui::Window::Window() :
    mWindow (sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Game"),
    mCurrentViewNumber  (250)
{
   mWindow.setFramerateLimit(80);
    // mViewNumbers["Default"] = 0;
    // mViews.push_back(mWindow.getDefaultView());
}

gui::Window::~Window() {}

// void 
// gui::Window::draw(auto& aTarget)
// {
//     allWindow.draw(aTarget);
// }

void 
gui::Window::draw(sf::Text& aTarget)
{
    mWindow.draw(aTarget);
}

void 
gui::Window::draw(sf::Sprite& aTarget)
{
    mWindow.draw(aTarget);
}

void 
gui::Window::clear()
{
    mWindow.clear(sf::Color::Black);
}

void 
gui::Window::display()
{
    mWindow.display();
}

void 
gui::Window::close()
{
    return mWindow.close();
}

// bool 
// gui::Window::isOpen()
// {
//     return allWindow.isOpen();
// }

bool 
gui::Window::pollEvent(sf::Event& event)
{
    return mWindow.pollEvent(event);
}

uint_8 
gui::Window::getViewNumber(str_const_ref aViewName)
{
    auto it = mViewNumbers.find(aViewName);
    if (it == mViewNumbers.end())
    {
        mViewNumbers[aViewName] = mViewNumbers.size();
        mViews.push_back(sf::View());
        it = mViewNumbers.find(aViewName);
    }
    return it->second;
}

void 
gui::Window::setView(uint_8 aViewNumber)
{
    if (mCurrentViewNumber != aViewNumber)
    {
        mWindow.setView(mViews[aViewNumber]);
    }
}

void
gui::Window::centrateView(uint_8 aViewNumber, sf_2f_const_ref aCoord)
{
    #ifdef _DBG_
    if (aViewNumber >= mViews.size() || aViewNumber < 0) 
    {
        dom::ErrorMessages::writeError("wiew_doesnt_exist", "view_number:", aViewNumber);
        return;
    }
    #endif

    mViews[aViewNumber].setCenter(aCoord);
}


void
gui::Window::centrateView(str_const_ref aViewName, sf_2f_const_ref aCoord)
{
    #ifdef _DBG_
    if (mViewNumbers.count(aViewName) == 0) 
    {
        dom::ErrorMessages::writeError("wiew_doesnt_exist", "view_name:", aViewName);
        return;
    }
    #endif

    centrateView(mViewNumbers[aViewName], aCoord);
    //mViews[mViewNumbers[aViewName]].setCenter(aCoord);
}