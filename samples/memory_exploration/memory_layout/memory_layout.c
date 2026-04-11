#include <stdio.h>
#include <stdlib.h>

int g_uninitialized; /* BSS */
int g_initialized = 123; /* Data */
const int g_const = 456; /* Read-only data */

void Demo(void)
{
	static int s = 789; /* static внутри функции */
	int local = 42; /* локальная переменная */
	int* heap = malloc(sizeof(int)); /* Heap */

	if (heap == NULL)
	{
		printf("malloc failed\n");
		return;
	}

	*heap = 100;

	printf("Address of function Demo     : %p\n", (void*)Demo);
	printf("Address of g_uninitialized   : %p\n", (void*)&g_uninitialized);
	printf("Address of g_initialized     : %p\n", (void*)&g_initialized);
	printf("Address of g_const           : %p\n", (void*)&g_const);
	printf("Address of static variable s : %p\n", (void*)&s);
	printf("Address of local variable    : %p\n", (void*)&local);
	printf("Address returned by malloc   : %p\n", (void*)heap);

	free(heap);
}

int main(void)
{
	Demo();
}