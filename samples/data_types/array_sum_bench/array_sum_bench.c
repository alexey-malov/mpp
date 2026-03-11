#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
#define N 300000000ULL

unsigned long long SumU16(const unsigned short* a, size_t n)
{
	unsigned long long sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

unsigned long long SumU32(const unsigned int* a, size_t n)
{
	unsigned long long sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

unsigned long long SumU64(const unsigned long long* a, size_t n)
{
	unsigned long long sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int main(void)
{
	unsigned long long sum;

	unsigned short* a16 = malloc(N * sizeof(unsigned short));
	unsigned int* a32 = malloc(N * sizeof(unsigned int));
	unsigned long long* a64 = malloc(N * sizeof(unsigned long long));

	if (a16 == NULL || a32 == NULL || a64 == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free(a16);
		free(a32);
		free(a64);
		return 1;
	}

	for (size_t i = 0; i < N; i++)
	{
		a16[i] = (unsigned short)(i & 0xFFFF);
		a32[i] = (unsigned int)i;
		a64[i] = (unsigned long long)i;
	}

	double t1 = Now();
	sum = SumU16(a16, N);
	double t2 = Now();
	printf("unsigned short:      sum = %llu, time = %.6f s\n", sum, t2 - t1);

	t1 = Now();
	sum = SumU32(a32, N);
	t2 = Now();
	printf("unsigned int:        sum = %llu, time = %.6f s\n", sum, t2 - t1);

	t1 = Now();
	sum = SumU64(a64, N);
	t2 = Now();
	printf("unsigned long long:  sum = %llu, time = %.6f s\n", sum, t2 - t1);

	free(a16);
	free(a32);
	free(a64);
}