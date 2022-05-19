#include "game/date.hpp"

sr::Date::Date() :
	mDate			(0)
{
	setLayer("Data");
	setView("Static");
	addTag("Data");

	mMonthNames =
	{
		"miden"s,
		"monary"s,
		"diary"s,
		"triary"s,
		"tetrary"s,
		"pentary"s,
		"hexary"s,
		"heptary"s,
		"octary"s,
		"enneary"s,
		"decary"s
	};
}

sr::Date::~Date() {}

void
sr::Date::update()
{
	++mDate;
	setText(getPresentation());
}

void
sr::Date::processEvent(gui::Event* aEvent)
{

}

str_val
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