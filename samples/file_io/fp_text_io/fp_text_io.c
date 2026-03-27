#include <math.h>
#include <stdio.h>

int main(void)
{
	FILE* f = fopen("pi.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}

	const double pi = 3.14159265358979323846;

	// Запись с ограниченной точностью
	fprintf(f, "%f\n", pi);

	if (fclose(f) == EOF)
	{
		perror("fclose");
		return 1;
	}

	f = fopen("pi.txt", "r");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}

	double pi1;
	if (fscanf(f, "%lf", &pi1) != 1)
	{
		fprintf(stderr, "Ошибка чтения\n");
		fclose(f);
		return 1;
	}

	fclose(f);

	printf("pi = %.15f\n", pi);
	printf("pi1 = %.15f\n", pi1);
	printf("difference = %.15f\n", pi - pi1);
}