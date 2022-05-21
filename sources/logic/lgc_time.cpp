#include "lgc_time.hpp"

lgc::Time lgc::Time::globalTime;

#define FPS_TIME_PAUSE (1000. / 80.)

lgc::Time::Time() :
    mdTime                  (0),
    mCumulativeTimeValue    (0),
    mFPSCount               (0)
{}

double
lgc::Time::updateTime()
{
    mdTime = mClock.restart().asMicroseconds() / 1000.;
    return mdTime;
}

double
lgc::Time::updateTimeAndFPS()
{
    mdTime = mClock.restart().asMicroseconds() / 1000.;
    mCumulativeTimeValue += mdTime;
    while (mCumulativeTimeValue > FPS_TIME_PAUSE)
    {
        mFPSCount++;
        mCumulativeTimeValue -= mdTime;
    }
    return mdTime;
}

uint_8
lgc::Time::getFPSDCount()
{
    return mFPSCount;
}

double
lgc::Time::getdTime()
{
    return mdTime;
}