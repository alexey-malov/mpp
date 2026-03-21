#include <stdio.h>

int main(void)
{
	double big = 1e16;
	double small = 1.0;

	double sum1 = big + small;
	double sum2 = (big + small) - big;

	printf("big   = %.17g\n", big);
	printf("small = %.17g\n", small);
	printf("big + small = %.17g\n", sum1);
	printf("(big + small) - big = %.17g\n", sum2);
	printf("\n");

	double a = 1e16;
	double b = -1e16;
	double c = 1.0;

	double r1 = (a + b) + c;
	double r2 = a + (b + c);

	printf("(a + b) + c = %.17g\n", r1);
	printf("a + (b + c) = %.17g\n", r2);
	printf("\n");

	double x = 0.1;
	double y = 0.2;
	double z = x + y;

	printf("0.1 + 0.2 = %.17g\n", z);
	printf("0.3       = %.17g\n", 0.3);
	printf("0.1 + 0.2 == 0.3 -> %s\n", (z == 0.3) ? "true" : "false");

	return 0;
}