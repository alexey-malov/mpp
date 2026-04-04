#include "point.h"

int main()
{
	Point* p = CreatePoint(1.0, 2.0);
	MovePoint(p, 3.0, 4.0);
	DestroyPoint(p);
}
