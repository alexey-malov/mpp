#include <math.h>
#include <stdio.h>

int main()
{
	double x1, y1, x2, y2;

	printf("Enter x1 y1: ");
	if (scanf("%lf %lf", &x1, &y1) != 2)
	{
		printf("Invalid input\n");
		return 1;
	}

	printf("Enter x2 y2: ");
	if (scanf("%lf %lf", &x2, &y2) != 2)
	{
		printf("Invalid input\n");
		return 1;
	}

	double dx = x2 - x1;
	double dy = y2 - y1;

	double distance = sqrt(dx * dx + dy * dy);

	printf("Distance = %.6f\n", distance);

	return 0;
}