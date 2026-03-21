#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main()
{
	float x;

	printf("Enter float: ");
	if (scanf("%f", &x) != 1)
	{
		printf("Invalid input\n");
		return 1;
	}

	uint32_t bits;
	memcpy(&bits, &x, sizeof(bits));

	uint32_t sign = (bits >> 31) & 0x1;
	uint32_t exponent = (bits >> 23) & 0xFF;
	uint32_t mantissa = bits & 0x7FFFFF;

	printf("x = %f\n", x);
	printf("bits     = 0x%08X\n", bits);
	printf("sign     = %u\n", sign);
	printf("exponent = 0x%02X (%u)\n", exponent, exponent);
	printf("mantissa = 0x%06X\n", mantissa);
}