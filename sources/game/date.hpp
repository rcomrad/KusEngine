#ifndef DATE_H
#define DATE_H

//--------------------------------------------------------------------------------

#include <vector>

#include "domain/dom_string.hpp"

#include "gui/gui_writable.hpp"

#include "logic/logic_object.hpp"

namespace sr
{
	class Date : public gui::Writable, public lgc::LogicObject
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