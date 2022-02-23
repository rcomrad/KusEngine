#include "core/my_time.hpp"

#define TARGET_FPS 100
#define SECOND_SIZE 1000

sr::Time::Time() {}
sr::Time::~Time() {}

double sr::Time::allLastTimeValue(0);
double sr::Time::allDTimeValue(0);
double sr::Time::all—umulativeTimeValue(0);
sf::Clock sr::Time::allClock;

void
sr::Time::updateTime()
{
 /*   double newTimeValue = getCPUTime();
	allDTimeValue = newTimeValue - allLastTimeValue;
	allLastTimeValue = newTimeValue;

	all—umulativeTimeValue += allDTimeValue;*/

    double time = allClock.getElapsedTime().asMicroseconds() / 1000.;
    allClock.restart();
    allDTimeValue = time;
    all—umulativeTimeValue += time;
    std::cout << allDTimeValue << std::endl;
}

double
sr::Time::getFPSDCount()
{
    if (all—umulativeTimeValue > 1000 / 80)
    {
        all—umulativeTimeValue = 0;
        return 1;
    }
    else return 0;
 //   //uint_16 gg = (SECOND_SIZE / TARGET_FPS);
	//uint_16 result = all—umulativeTimeValue / (SECOND_SIZE / TARGET_FPS);
	//all—umulativeTimeValue = 
 //       uint_64(all—umulativeTimeValue) % (SECOND_SIZE / TARGET_FPS);
	//return result;
}

double
sr::Time::getDTime()
{
    return allDTimeValue;
}

/*
 * Author:  David Robert Nadeau
 * Site:    http://NadeauSoftware.com/
 * License: Creative Commons Attribution 3.0 Unported License
 *          http://creativecommons.org/licenses/by/3.0/deed.en_US
 */
#if defined(_WIN32)
#include <Windows.h>

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
#include <unistd.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>

#else
#error "Unable to define getCPUTime( ) for an unknown OS."
#endif

 /**
  * Returns the amount of CPU time used by the current process,
  * in seconds, or -1.0 if an error occurred.
  */


double getTime() {
    LARGE_INTEGER freq, val;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&val);
    return (double)val.QuadPart / (double)freq.QuadPart;
}

double getCPUTime()
{
#if defined(_WIN32)

    // function to measure
    double timeInMilliseconds = 1000 * (getTime());
    return timeInMilliseconds;

    /* Windows -------------------------------------------------- */
    FILETIME createTime;
    FILETIME exitTime;
    FILETIME kernelTime;
    FILETIME userTime;
    if (GetProcessTimes(GetCurrentProcess(),
        &createTime, &exitTime, &kernelTime, &userTime) != -1)
    {
        SYSTEMTIME userSystemTime;
        FileTimeToSystemTime(&userTime, &userSystemTime);
        if (FileTimeToSystemTime(&userTime, &userSystemTime) != -1)
            return (double)userSystemTime.wHour * 3600.0 +
            (double)userSystemTime.wMinute * 60.0 +
            (double)userSystemTime.wSecond +
            (double)userSystemTime.wMilliseconds / 1000.0;
    }

#elif defined(__unix__) || defined(__unix) || defined(unix) || (defined(__APPLE__) && defined(__MACH__))
    /* AIX, BSD, Cygwin, HP-UX, Linux, OSX, and Solaris --------- */

#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0)
    /* Prefer high-res POSIX timers, when available. */
    {
        clockid_t id;
        struct timespec ts;
#if _POSIX_CPUTIME > 0
        /* Clock ids vary by OS.  Query the id, if possible. */
        if (clock_getcpuclockid(0, &id) == -1)
#endif
#if defined(CLOCK_PROCESS_CPUTIME_ID)
            /* Use known clock id for AIX, Linux, or Solaris. */
            id = CLOCK_PROCESS_CPUTIME_ID;
#elif defined(CLOCK_VIRTUAL)
            /* Use known clock id for BSD or HP-UX. */
            id = CLOCK_VIRTUAL;
#else
            id = (clockid_t)-1;
#endif
        if (id != (clockid_t)-1 && clock_gettime(id, &ts) != -1)
            return (double)ts.tv_sec +
            (double)ts.tv_nsec / 1000000000.0;
    }
#endif

#if defined(RUSAGE_SELF)
    {
        struct rusage rusage;
        if (getrusage(RUSAGE_SELF, &rusage) != -1)
            return (double)rusage.ru_utime.tv_sec +
            (double)rusage.ru_utime.tv_usec / 1000000.0;
    }
#endif

#if defined(_SC_CLK_TCK)
    {
        const double ticks = (double)sysconf(_SC_CLK_TCK);
        struct tms tms;
        if (times(&tms) != (clock_t)-1)
            return (double)tms.tms_utime / ticks;
    }
#endif

#if defined(CLOCKS_PER_SEC)
    {
        clock_t cl = clock();
        if (cl != (clock_t)-1)
            return (double)cl / (double)CLOCKS_PER_SEC;
    }
#endif

#endif

    return -1;      /* Failed. */
}