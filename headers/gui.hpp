#ifndef GUI_H
#define GUI_H

//--------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "domain.hpp"
#include "window.h"
#include "player.hpp"
#include "background.hpp"
#include "drawable.hpp"



class GUI : MyWindow
//class GUI
{
public:
	enum EventType
	{
		NUN					=	0,
		SWITCH_DRAW_MODE	=	1,
		SWITCH_PAUSE		=	2,
		INCREASE_SPEED		=	3,
		DECREASE_SPEED		=	4,
		STANDART_PAUSE		=	5
	};

	GUI(sint_16 aN, sint_16 aM);

	bool isAppClosed() const;
	std::vector<EventType> getEvents();

	void drawField();

private:
	std::vector<MyDrawable*> mDrawableObjects;
	//sf::RenderWindow mWindow;
};

//--------------------------------------------------------------------------------

#endif // GUI_H