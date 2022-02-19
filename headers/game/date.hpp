#ifndef DATE_H
#define DATE_H

//--------------------------------------------------------------------------------

#include "core/domain.hpp"
#include <vector>
#include "gui/writable.hpp"
#include "game/game_object.hpp"

namespace sr
{
	class Date : public GameObject, public Writable
	{
	public:
		Date();
		virtual ~Date();
		void update();
		std::string getPresentation();
		virtual void processEvent(Event* aEvent);
	private:
		sint_64 mDate;
		std::vector<std::string> mMonthNames;
	};
}

//--------------------------------------------------------------------------------

#endif // !DATE_H