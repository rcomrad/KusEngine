#include "core/core.hpp"

//uint64_t nDays(uint64_t y, uint64_t m, uint64_t d) {
//	if (m <= 2) m += 12, y -= 1;
//	return (y * 146097) / 400 + (m * 153 + 8) / 5 + d;
//}

#include "game/date.hpp"

class A
{
public:
	A(int a):
		n (a)
	{

	}

	int n;
};

class B : public A
{
public:
	B() :
		A(2)
	{

	}
};

class C : public A
{
public:
	C() :
		A(4)
	{

	}
};

class D : public B, public C
{
public:
	D(){}
};


#include <vector>
int main()
{
	//B b;
	//std::cout << b.n;
	//C c;
	//std::cout << c.n;
	//D d;
	//std::cout << d.n;

	//sr::Date d;

	//while (true)
	//{
	//	std::cout << d.getPresentation() << std::endl;
	//	d.update();
	//	for (int i = 0; i < 1e7; ++i);
	//}

	//uint64_t rr1 = nDays(1000, 7, 12);
	//uint64_t rr2 = nDays(2023, 7, 12);
	//std::cout << rr2 - rr1 << std::endl;

	sr::Core g;
	g.run();
}



/*
��� ����� ���� ���
1000 10 10 10
*/