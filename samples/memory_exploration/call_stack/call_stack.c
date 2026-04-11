#include <stdio.h>

void B(const char* from)
{
	int y = 2;
	printf("B called from %s: y=%d, &y=%p\n", from, y, (void*)&y);
}

void A(void)
{
	int x = 1;
	printf("A: x=%d, &x=%p\n", x, (void*)&x);
	B("A");
}

int main(void)
{
	B("main before A");
	A();
	B("main after A");
}