#include "game.hpp"

Game::Game() 
{
	mObjects.insert(new Player(TEXTURES + "player.png"));
	mObjects.insert(new Background(TEXTURES + "background.png"));

	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
	//mObjectss.push_back(new Player(TEXTURES + "background.png"));
}

Game::~Game() 
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


void
Game::run(std::vector<Event*> aEvents)
{
	//A* a = new C;
	//a->foo();

	((SpaceObject*)(*(--mObjects.end())))->update();

	std::set<MyDrawable*, DrawableComparator> mmm;

	std::set<MyDrawable*, DrawableComparator>* mmmm = &mmm;
	int ss = sizeof(mmm);


	//for (auto i : aEvents) std::cout << i->getEventType();
	for (Event* i : aEvents)
	{
		if (i->getEventType() == Event::EventType::MOVE)
		{
			MoveEvent* me = static_cast <MoveEvent*> (i);
			std::cout << me->mCoord.x << " " << me->mCoord.y << "\n";

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

			((GameObject*)(*(--mObjects.end())))->processEvent(i);

		}
	}


}




const std::set<MyDrawable*, DrawableComparator>*
Game::getPresentation() const
{
	return &mObjects;
}