#include <stdio.h>

typedef struct
{
	double x;
	double y;
} Point;

int main(void)
{
	FILE* f = fopen("point.txt", "r");
	if (f == NULL)
	{
		perror("Open failed");
		return 1;
	}

	Point p;

	if (fscanf(f, "%lf %lf", &p.x, &p.y) != 2)
	{
		fprintf(stderr, "Read error\n");
		fclose(f);
		return 1;
	}

	fclose(f);
	printf("Point: (%f, %f)\n", p.x, p.y);
}