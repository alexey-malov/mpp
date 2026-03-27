#include <stdio.h>

int main(void)
{
	int a, b;

	if (fscanf(stdin, "%d %d", &a, &b) != 2)
	{
		fprintf(stderr, "Input error: expected two integers\n");
		return 1;
	}

	fprintf(stdout, "Sum = %d\n", a + b);
}