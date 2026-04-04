#include <stdio.h>
#include <stdlib.h>

// Компаратор для сортировки по возрастанию
int CompareAscending(const void* a, const void* b)
{
	int x = *(const int*)a;
	int y = *(const int*)b;

	return (x < y) ? -1 : (x > y) ? 1
								  : 0;
}

// Компаратор для сортировки по убыванию
int CompareDescending(const void* a, const void* b)
{
	return -CompareAscending(a, b);
}

int main(void)
{
	int a[] = { 5, 2, 9, 1, 5, 6 };
	int n = sizeof(a) / sizeof(a[0]);

	// Сортировка по возрастанию
	qsort(a, n, sizeof(int), CompareAscending);

	printf("Ascending: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	// Сортировка по убыванию
	qsort(a, n, sizeof(int), CompareDescending);

	printf("Descending: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
