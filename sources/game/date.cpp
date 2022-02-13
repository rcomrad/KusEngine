#include "game/date.hpp"

sr::Date::Date() :
	mDate(0)
{
	mMonthNames =
	{
		"miden",
		"monary",
		"diary",
		"triary",
		"tetrary",
		"pentary",
		"hexary",
		"heptary",
		"octary",
		"enneary",
		"decary"
	};
}

sr::Date::~Date() {}

void
sr::Date::update()
{
	++mDate;
}

std::string 
sr::Date::getPresentation()
{
	std::string result;
	sint_64 dateCopy = mDate;

	for (int i = 0; i < 2; ++i)
	{
		result += std::to_string(dateCopy % 10) + '.';
		dateCopy /= 10;
	}

	result += mMonthNames[dateCopy % 10] + '.';
	dateCopy /= 10;

	result += std::to_string(dateCopy);

	return result;
}