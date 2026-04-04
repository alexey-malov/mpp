#ifndef SHAPES_H
#define SHAPES_H

#include <stdint.h>

typedef struct Shape Shape;

typedef struct
{
	double x;
	double y;
} Point;

typedef struct
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} Color;

void ShapeDraw(const Shape* s);
double ShapeGetArea(const Shape* s);

Shape* CreateCircle(Color color, Point center, double radius);
Shape* CreateRectangle(Color color, Point leftTop, double width, double height);
void DestroyShape(Shape* s);

#endif // SHAPES_H