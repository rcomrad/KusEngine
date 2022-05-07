#ifndef MY_TIME_HPP
#define MY_TIME_HPP

//--------------------------------------------------------------------------------

#include "SFML/System/Clock.hpp"

#include "domain.hpp"

namespace sr
{
	class Time
	{
	public:
		Time();
		virtual ~Time();

		static void updateTime();
		static double getFPSDCount();
		static double getDTime();

	private:
		static double allLastTimeValue;
		static double allDTimeValue;

		static double allCumulativeTimeValue;

		static sf::Clock allClock;
	};
}

double getCPUTime();

//--------------------------------------------------------------------------------

#endif // !MY_TIME_HPP