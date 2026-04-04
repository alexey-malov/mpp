#include "shapes.h"
#include <stdio.h>

int main(void)
{
	Shape* shapes[] = {
		CreateCircle((Color){255, 0, 0}, (Point){ 3.5, 10.2 }, 10.0),
		CreateRectangle((Color){ 255, 255, 0 }, (Point){ -1.0, 2.0 }, 5.0, 3.0)
	};

	const size_t numShapes = sizeof(shapes) / sizeof(*shapes);

	for (int i = 0; i < numShapes; i++)
	{
		ShapeDraw(shapes[i]);
		printf("Area = %.2f\n", ShapeGetArea(shapes[i]));
	}

	return 0;
}