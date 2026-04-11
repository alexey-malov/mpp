#include <stdalign.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

double Now(void)
{
	LARGE_INTEGER freq, counter;
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&counter);
	return (double)counter.QuadPart / (double)freq.QuadPart;
}

#else
#include <time.h>

double Now(void)
{
	struct timespec t;
	clock_gettime(CLOCK_MONOTONIC, &t);
	return (double)t.tv_sec + (double)t.tv_nsec * 1e-9;
}
#endif

enum
{
	CACHE_LINE_SIZE = 64,
	ITERATIONS = 2000000000ull
};

alignas(CACHE_LINE_SIZE) static uint8_t gData[CACHE_LINE_SIZE];

uint64_t SumCacheLine(size_t x, size_t y)
{
	uint64_t sum = 0;
	size_t pos = 0;

	for (uint64_t i = 0; i < ITERATIONS; ++i)
	{
		sum += gData[pos];
		pos = (pos * x + y) % sizeof(gData);
	}

	return sum;
}

// Указатель на функцию, время которой надо измерить
typedef void (*MeasuredFunc)(void*);

void Measure(const char* name, MeasuredFunc fn, void* ctx)
{
	double t0 = Now();
	fn(ctx);
	double t1 = Now();
	printf("%s: %.6f sec\n", name, t1 - t0);
}

typedef struct
{
	size_t x;
	size_t y;
} SumContext;

void SumCacheLineWithContext(void* ctx)
{
	SumContext* sumCtx = ctx;
	volatile uint64_t unused = SumCacheLine(sumCtx->x, sumCtx->y);
	(void)unused;
}

int main(void)
{
	for (size_t i = 0; i < sizeof(gData); ++i)
	{
		gData[i] = (uint8_t)i;
	}
	SumContext seqCtx = { 1, 1 };
	Measure("sequential", SumCacheLineWithContext, &seqCtx);
	SumContext randCtx = { 13, 17 };
	Measure("pseudo-random", SumCacheLineWithContext, &randCtx);
}