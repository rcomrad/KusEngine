#ifndef DOMAIN_H
#define DOMAIN_H

#define _CRT_SECURE_NO_WARNINGS

// ChineseTester_D_NewVegasEdition_V0.7
// ChineseTester_R_NewVegasEdition_V0.7

#if 1
#define LOG_TO_FILE_OUTPUT
#endif

#if 0
#define PIPE_LOG_OUTPUT
#endif

#if 1
#define COMPILER_LOG_OUTPUT
#endif

#if defined(WIN32) || defined(WIN_BY_ME)
#define BILL_WINDOWS
#endif

#ifndef BILL_WINDOWS
#define LINUS_LINUX
#endif

#ifdef _DEBUG
#define _DBG_
#define CHINESE_DEBUG
#endif

#undef  _DBG_

#ifdef CHINESE_DEBUG

#if 0
#define TRUE_ONLY_WAY
#endif

#define _DBG_
#define GOOD_DEBUG_ERRORS
#endif

#define MAIN_PATH       getMainPath()
#define RESOURCES       MAIN_PATH   + "resources\\"
#define TEXTURES        RESOURCES   + "textures\\"

#define _(aName) #aName

#define W_LOG(aMessege)                                 \
    {                                                   \
        std::cout <<aMessege << "\n";                   \
    }

#define W_END_LOG                                       \
    {                                                   \
        std::cout << std::endl;                         \
    }

#ifdef  GOOD_DEBUG_ERRORS
#define W_ERROR(aNumber, aMessege)                      \
    {                                                   \
        std::cout << "\n\n\x1b[31m!!!!!!!!! "           \
            "ERROR HAS OCCURRED !!!!!!!!!\n\n"          \
            << "ERROR# " #aNumber "\n"                  \
            << aMessege << "\x1b[0m\n\n" << std::endl;  \
        exit(0);                                        \
    }
#else
#define W_ERROR(aNumber, aMessege)                      \
    {                                                   \
        std::cout << std::string("\n\n!!!!!!!!! "      \
            "ERROR HAS OCCURRED !!!!!!!!!\n"            \
            "ERROR# " #aNumber "\n") +                  \
            std::string(aMessege) +                     \
            std::string( "" "\n\n" "\n\n" )             \
            << std::endl; exit(0);                      \
    }
#endif

#ifdef _DBG_
    #define WD_LOG(aMessege) W_LOG(aMessege) 
    #define WD_END_LOG W_END_LOG 
    #define WD_ERROR(aNumber, aMessege) W_ERROR(aNumber, aMessege) 
#else
    #define WD_LOG(aMessege) 
    #define WD_END_LOG
    #define WD_ERROR(aNumber, aMessege)
#endif // DEBUG

#define print(aMessage)         \
{                               \
    std::cout << aMessage;      \
}
#define _CRT_SECURE_NO_WARNINGS
typedef signed char		    sint_8;
typedef unsigned char	    uint_8;
typedef signed short	    sint_16;
typedef unsigned short	    uint_16;
typedef signed long		    sint_32;
typedef unsigned long	    uint_32;
typedef signed long	long	sint_64;
typedef unsigned long long	uint_64;

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>

std::string getMainPath();

template <typename T>
union Pair
{
	struct
	{
		T i, j;
	};
	struct
	{
		T x, y;
	};
	struct
	{
		T first, second;
	};

	Pair()
	{
		i = j = 0;
	}
	Pair(const T iInit, const T jInit) :
		i(iInit),
		j(jInit)
	{}

	T& operator[] (const int num)
	{
		return num ? j : i;
	}

	void operator+= (const Pair& n)
	{
		i += n.i;
		j += n.j;
	}
	void operator-= (const Pair& n)
	{
		i -= n.i;
		j -= n.j;
	}

	Pair operator+ (const Pair& n) const
	{
		Pair ret;
		ret.i = i + n.i;
		ret.j = j + n.j;
		return ret;
	}
	Pair operator- (const Pair& n) const
	{
		Pair ret;
		ret.i = i - n.i;
		ret.j = j - n.j;
		return ret;
	}

	bool operator< (const Pair& n) const
	{
		if (i != n.i) return i < n.i;
		return j < n.j;
	}
	bool operator>(const Pair& n) const
	{
		if (i != n.i) return i > n.i;
		return j > n.j;
	}
	bool operator== (const Pair& n) const
	{
		return i == n.i && j == n.j;
	}
	bool operator!= (const Pair& n) const
	{
		return i != n.i || j != n.j;
	}
};


#endif //DOMAIN_H