#include "game/game.hpp"




sr::Game::Game() :
	mPause(false)
{

	//Player p(TEXTURES + "player.png");
	//Background b(TEXTURES + "background.png");
	//Date d;

	//void* gg = (void*) &p;
	//Player* p3 = (Player*)gg;

	//std::set<void*> af;
	//af.insert((GuiOutputBase*)&p);
	//af.insert((GuiOutputBase*)&p);
	//Player* p4 = (Player*)((*(-- -- af.begin())));
	//Spaceship* p44 = (Spaceship*)((*(-- --af.begin())));
	//SpaceObject* p443 = (SpaceObject*)((*(-- --af.begin())));
	//Drawable* p444 = (Drawable*)((*(-- --af.begin())));
	//GuiOutputBase* p5 = (GuiOutputBase*)((*(-- --af.begin())));

	//mObjects.insert((void*) &p);
	//mObjects.insert((void*) &b);
	//mObjects.insert((void*) &d);
	//mObjects.insert((Background*)(*(--mObjects.end())));

	//Player* pp = (Player*) (*(--mObjects.end()));
	//Date* dd = (Date*)(*(-- --mObjects.end()));
	//Background* bb = (Background*)(*(-- -- --mObjects.end()));


	//mObjects.insert((GuiOutputBase*)new Player(TEXTURES + "player.png"));
	//mObjects.insert((GuiOutputBase*)new Background(TEXTURES + "background.png"));
	//mObjects.insert((GuiOutputBase*)new Date());

	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
	//mObjectss.push_back(new Player(TEXTURES + "background.png"));

	Player* p = new Player();
	Background* b = new Background();
	Planet* pp = new Planet();
	Date* d = new Date();

	mObjectsDrawSide.insert(p);
	mObjectsDrawSide.insert(b);
	mObjectsDrawSide.insert(d);
	mObjectsDrawSide.insert(pp);

	mObjectsLogicSide.insert(p);
	mObjectsLogicSide.insert(b);
	mObjectsLogicSide.insert(d);
	mObjectsLogicSide.insert(pp);
}

sr::Game::~Game()
{
	//for (auto i : mObjects) delete i;
	for (auto i : mObjectsDrawSide) delete i;
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

	//void* ii = (*(--mObjects.end()));
	//GuiOutputBase* sus = static_cast<GuiOutputBase*> (ii);
	//GameObject* sus2 = static_cast<GameObject*> (ii);
	//Player* sus3 = static_cast<Player*> (sus2);
	//sus3->update();

	if (!mPause)
	{
		//((SpaceObject*)(*(--mObjects.end())))->update();
		//for (auto i : mObjects)
		for (auto i : mObjectsLogicSide)
		{
			////GameObject* sus = ((GameObject*)i);
			//GuiOutputBase* sus = static_cast<GuiOutputBase*> (i);
			//GameObject* sus2 = static_cast<GameObject*> (i);
			i->update();
		}
	}

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
			break;
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

	//((GameObject*)(*(--mObjects.end())))->
	//	processEvent(aEvent);

	for (auto i : mObjectsLogicSide)
	{
		////GameObject* sus = ((GameObject*)i);
		//GuiOutputBase* sus = static_cast<GuiOutputBase*> (i);
		//GameObject* sus2 = static_cast<GameObject*> (i);
		i->processEvent(aEvent);
	}
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

	//mObjectsDrawSide.erase(d);
	//mObjectsLogicSide.erase(d);
}


const SET_DRAWEBLE_TYPE*
sr::Game::getPresentation() const
{
	//Player* pp = (Player*)(*(--mObjects.end()));

	//return &mObjects;
	return &mObjectsDrawSide;
}