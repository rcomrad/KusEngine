#ifndef DATE_H
#define DATE_H

//--------------------------------------------------------------------------------

#include <vector>

#include "domain/dom_string.hpp"

#include "gui/gui_writable.hpp"

#include "game/game_object.hpp"

namespace sr
{
	class Date : public GameObject, public gui::Writable
	{
	public:
		Date();
		virtual ~Date();
		void update();
		str_val getPresentation();
		virtual void processEvent(gui::Event* aEvent);
	private:
		sint_64 mDate;
		std::vector<str_val> mMonthNames;
		//std::vector<str_const_ref> mMonthNames;
	};
}

//--------------------------------------------------------------------------------

#endif // !DATE_H