#include "game/game.hpp"

sr::Game::Game() :
	mPause(false)
{
	mObjects.insert(new Player(TEXTURES + "player.png"));
	mObjects.insert(new Background(TEXTURES + "background.png"));

	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
}

sr::Game::~Game()
{
	for (auto i : mObjects) delete i;
}

//struct A
//{
//	virtual void foo() = 0;
//};
//
//struct B : public A
//{
//	virtual void foo() {
//		std::cout << "lol\n";
//	}
//};
//
//struct C : public B
//{
//};


bool
sr::Game::run(std::vector<Event*> aEvents)
{
	//A* a = new C;
	//a->foo();

	if (!mPause) ((SpaceObject*)(*(--mObjects.end())))->update();

	//std::set<Drawable*, DrawableComparator> mmm;

	//std::set<Drawable*, DrawableComparator>* mmmm = &mmm;
	//int ss = sizeof(mmm);


	//for (auto i : aEvents) std::cout << i->getEventType();
	for (Event* i : aEvents)
	{
		switch (i->getEventType())
		{
		case Event::EventType::MOVE:
			mouseEventsHandler(i);
			break;
		case Event::EventType::KEY_PRESSED:
			keyEventsHandler(i);
		case Event::EventType::CLOSE:
			return true;
			break;
		}
	}

	return false;
}

void 
sr::Game::mouseEventsHandler(Event* aEvent)
{
	sr::MoveEvent* moveEvent = static_cast <MoveEvent*> (aEvent);
	std::cout << moveEvent->mCoord.x << " " << moveEvent->mCoord.y << "\n";

	//auto it = mObjects.rend();
	////auto itt = *((std::vector<int>::iterator) mObjects.rend());
	//void* sosi = mObjects.rend().base()._Ptr;
	////MyDrawable* const* g = &(*mObjects.rend());
	////MyDrawable* const* g = static_cast<
	//MyDrawable* gg = (MyDrawable*)  sosi;
	//GameObject* ggg = (GameObject*) (gg);


	//const MyDrawable* g = &(*(--mObjectss.end()));
	//((GameObject*)mObjectss[0])->processEvent(aEvents[0]);
	//return;

	//const MyDrawable* g = (*(--mObjects.end()));
	//MyDrawable* gg = (MyDrawable*)g;
	//GameObject* ggg = (GameObject*)(gg);
	//ggg->processEvent(i);

	((GameObject*)(*(--mObjects.end())))->
		processEvent(aEvent);
}

void 
sr::Game::keyEventsHandler(Event* aEvent)
{
	sr::KeyEvent* moveEvent = static_cast <KeyEvent*> (aEvent);

	switch (moveEvent->mType)
	{
	case KeyEvent::KeyEventType::SPACE_PAUSE:
		mPause = !mPause;
		break;
	}
}


const std::set<sr::Drawable*, sr::DrawableComparator>*
sr::Game::getPresentation() const
{
	return &mObjects;
}