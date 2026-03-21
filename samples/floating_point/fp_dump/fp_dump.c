#include <inttypes.h>
#include <stdio.h>

void PrintDump(const void* addr, size_t size)
{
	const uint8_t* p = (const uint8_t*)addr;
	for (size_t i = 0; i < size; i++)
	{
		printf("%02X ", p[i]);
	}
	printf("\n");
}

int main()
{
	float f = 1.0f;
	double d = 1.0;
	PrintDump(&f, sizeof(f));
	PrintDump(&d, sizeof(d));
}