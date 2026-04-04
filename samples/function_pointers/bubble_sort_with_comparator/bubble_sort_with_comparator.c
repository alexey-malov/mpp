#include <stdio.h>

// Указатель на функцию, которая сравнивает два элемента.
// Функция должна вернуть:
//  - отрицательное значение, если a < b,
//  - ноль, если a == b,
//  - положительное значение, если a > b.
typedef int (*Comparator)(int, int);

void BubbleSort(int* a, int n, Comparator cmp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			// Если компаратор возвращает положительное значение,
			// значит элементы не упорядочены, и их нужно поменять местами.
			if (cmp(a[j], a[j + 1]) > 0)
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

int AscendingComparator(int a, int b)
{
	return a < b ? -1 : (a > b ? 1 : 0); // Сортировка по возрастанию
}

int DescendingComparator(int a, int b)
{
	return -AscendingComparator(a, b); // Сортировка по убыванию
}

int main()
{
	int a[] = { 5, 2, 9, 1, 5, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n, AscendingComparator);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}