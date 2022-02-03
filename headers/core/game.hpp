#ifndef GAME_H
#define GAME_H

//--------------------------------------------------------------------------------

#include <iostream>

#include "program_state.hpp"
#include "player.hpp"
#include "background.hpp"

class Game : public ProgramState
{
public:
	Game();
	~Game();

	virtual void run(std::vector<Event*> aEvents);
	virtual
		const std::set<MyDrawable*, DrawableComparator>*
		getPresentation() const;
private:
	std::set<MyDrawable*, DrawableComparator> mObjects;
	//std::vector<MyDrawable*> mObjectss;
};

//--------------------------------------------------------------------------------

#endif // !GAME_H