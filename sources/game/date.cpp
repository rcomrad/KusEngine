#include "game/date.hpp"

#define DAY_SPEED 1000.

sr::Date::Date() :
	mDate			(0),
	mTime			(0)
{
	setLayer("Data");
	setView("Static");

	mMonthNames =
	{
		"miden"s,	// 0
		"monary"s,	// 1
		"diary"s,	// 2
		"triary"s,	// 3
		"tetrary"s,	// 4
		"pentary"s,	// 5	
		"hexary"s,	// 6
		"heptary"s,	// 7
		"octary"s,	// 8
		"enneary"s,	// 9
		//"decary"s
	};

	setText(getPresentation());
}

std::shared_ptr<sr::Date>
sr::Date::create()
{
	std::shared_ptr<sr::Date> result (new Date);
	result->addTag("Data");
	result->Writable::create();
	result->LogicObject::create();
	return result;
}


void
sr::Date::update(float adTime)
{
	mTime += adTime;
	if (mTime > DAY_SPEED)
	{
		mTime = 0;
		++mDate;
		setText(getPresentation());
	}
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