#ifndef MY_TIME_HPP
#define MY_TIME_HPP

//--------------------------------------------------------------------------------

#include <SFML/System/Clock.hpp>

#include "domain/dom_type.hpp"

namespace lgc
{
	class Time
	{
	public:
		static Time globalTime;

		Time();
		virtual ~Time() = default;

		double updateTime();
		double updateTimeAndFPS();
		uint_8 getFPSDCount();
		double getdTime();

	private:
		sf::Clock mClock;
		double mdTime;
		double mCumulativeTimeValue;
		uint_8 mFPSCount;
	};
}

double getCPUTime();

//--------------------------------------------------------------------------------

#endif // !MY_TIME_HPP