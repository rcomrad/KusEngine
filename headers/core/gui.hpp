#ifndef GUI_H
#define GUI_H

//--------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include <SFML/Graphics.hpp>

#include "domain.hpp"
#include "window.hpp"
#include "player.hpp"
#include "background.hpp"
#include "drawable.hpp"

#include "event.hpp"

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
	std::vector<Event*> getEvents();

	void drawObjects
	(
		const 
		std::set<MyDrawable*, DrawableComparator>* 
		aDrawableObjects
	);

private:
	//std::set<MyDrawable*> mDrawableObjects;
	//std::set<MyDrawable*> mDrawableObjects;
	//sf::RenderWindow mWindow;
	//auto ;
	//std::set<int, decltype(cmp)> s;
	;
};

//--------------------------------------------------------------------------------

#endif // GUI_H