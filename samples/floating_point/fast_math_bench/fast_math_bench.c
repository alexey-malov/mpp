#include <math.h>
#include <stdint.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

double Now()
{
	LARGE_INTEGER freq, counter;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);
	return (double)counter.QuadPart / freq.QuadPart;
}

#else
#include <time.h>

double Now()
{
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	return t.tv_sec + t.tv_nsec * 1e-9;
}
#endif

int main(void)
{
	const int N = 100000000;
	double sink = 0.0;

	double start = Now();

	for (int i = 1; i <= N; i++)
	{
		double x = i * 0.000001;
		sink += sin(x) * cos(x) + sqrt(x + 1.0);
	}

	double end = Now();

	printf("result = %.17g\n", sink);
	printf("time   = %.6f sec\n", end - start);
}