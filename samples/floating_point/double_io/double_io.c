#include <stdio.h>

int main()
{
	double radius;

	printf("Enter radius: ");
	if (scanf("%lf", &radius) != 1)
	{
		printf("Invalid input\n");
		return 1;
	}

	double area = 3.141592653589793 * radius * radius;

	printf("Area = %.6f\n", area);
}