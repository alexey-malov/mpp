#include <stdio.h>

int main()
{
	double eps = 1.0;

	while (1.0 + eps / 2.0 != 1.0)
	{
		eps /= 2.0;
	}

	printf("epsilon = %.17g\n", eps);
}