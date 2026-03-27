#include <stdio.h>

typedef struct
{
	double x;
	double y;
} Point;

int main(void)
{
	FILE* f = fopen("point.txt", "w");
	if (f == NULL)
	{
		perror("Open error");
		return 1;
	}

	Point p = { 1.5, -2.3 };
	fprintf(f, "%lf %lf\n", p.x, p.y);
	fclose(f);
}