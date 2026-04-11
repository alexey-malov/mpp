#include <stdio.h>

void B(const char* from)
{
	static int x = 0;
	x++;
	printf("B called from %s: x=%d, &x=%p\n", from, x, (void*)&x);
}

void A(void)
{
	B("A");
}

int main(void)
{
	B("main");
	A();
	B("main again");
	return 0;
}