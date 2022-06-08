#ifndef DATE_H
#define DATE_H

//--------------------------------------------------------------------------------

#include <vector>

#include "domain/string.hpp"

#include "gui/writable.hpp"

#include "logic/logic_object.hpp"

namespace sr
{
	class Date : public gui::Writable, public lgc::LogicObject
	{
	public:
		virtual ~Date() = default;
		static std::shared_ptr<sr::Date> create();

		void update(float adTime);
		str_val getPresentation();

	private:
		sint_64 mDate;
		std::vector<str_val> mMonthNames;
		float mTime;

		Date();
	};
}

//--------------------------------------------------------------------------------

#endif // !DATE_H