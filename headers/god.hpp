#ifndef GOD_H
#define GOD_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "gui.hpp"

class God
{
public:
	God();
	~God();

	void run();

private:
	GUI mView;

	bool mNeedToDraw;
	bool mIsTurnedOff;

	uint_64 mPauseTime = 1 * 7 * 7 * 7 * 7 * 7 * 7 * 7;
};

//--------------------------------------------------------------------------------

#endif // GOD_H