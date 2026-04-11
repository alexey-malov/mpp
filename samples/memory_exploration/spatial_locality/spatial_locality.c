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

#define N 8192

/* Доступ как m[i][j] -> m[i * N + j] */
void RowMajor(int* m)
{
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			m[i * N + j] += 1;
		}
	}
}

void ColumnMajor(int* m)
{
	for (size_t j = 0; j < N; ++j)
	{
		for (size_t i = 0; i < N; ++i)
		{
			m[i * N + j] += 1;
		}
	}
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
	void (*fn)(int*);
	int* data;
} MatrixContext;

void MatrixMeasured(void* ctx)
{
	MatrixContext* mc = ctx;
	mc->fn(mc->data);
}

int main(void)
{
	int* m = (int*)malloc(sizeof(int) * N * N);
	if (!m)
	{
		printf("malloc failed\n");
		return 1;
	}

	/* Инициализация */
	for (size_t i = 0; i < N * N; ++i)
	{
		m[i] = 0;
	}

	MatrixContext rowCtx = { RowMajor, m };
	MatrixContext colCtx = { ColumnMajor, m };

	Measure("row-major", MatrixMeasured, &rowCtx);
	Measure("column-major", MatrixMeasured, &colCtx);

	free(m);
}