#ifndef DATE_H
#define DATE_H

//--------------------------------------------------------------------------------

#include "core/domain.hpp"
#include <vector>

namespace sr
{
	class Date
	{
	public:
		Date();
		virtual ~Date();
		void update();
		std::string getPresentation();

	private:
		sint_64 mDate;
		std::vector<std::string> mMonthNames;
	};
}

//--------------------------------------------------------------------------------

#endif // !DATE_H