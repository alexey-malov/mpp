#include "point.h"
#include <assert.h>

struct Point {
	double x;
	double y;
};

Point* CreatePoint(double x, double y) {
	Point* point = (Point*)malloc(sizeof(Point));
	if (point) {
		point->x = x;
		point->y = y;
	}
	return point;
}

void DestroyPoint(Point* point) {
	free(point);
}

void MovePoint(Point* point, double dx, double dy) {
	assert(point != NULL);
	point->x += dx;
	point->y += dy;
}
