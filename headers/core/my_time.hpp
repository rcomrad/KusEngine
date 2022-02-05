#ifndef MY_TIME_HPP
#define MY_TIME_HPP

//--------------------------------------------------------------------------------

#include "domain.hpp"
#include "getCPUTime.h"

class MyTime
{
public:
	MyTime();
	virtual ~MyTime();

	static void updateTime();
	static double getFPSDCount();
	static double getDTime();

private:
	static double allLastTimeValue;
	static double allDTimeValue;

	static double all—umulativeTimeValue;
};

double getCPUTime();

//--------------------------------------------------------------------------------

#endif // !MY_TIME_HPP