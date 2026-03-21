#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

typedef struct
{
	int32_t integer; // целая часть (со знаком)
	uint32_t fraction; // дробная часть (без знака)
} Fixed;

Fixed FixedAdd(Fixed a, Fixed b)
{
	Fixed result;
	result.integer = a.integer + b.integer;
	result.fraction = a.fraction + b.fraction;
	if (result.fraction < a.fraction) // проверка на переполнение дробной части
	{
		result.integer += 1; // перенос единицы в целую часть
	}

	return result;
}

int main()
{
	Fixed a = { 1, 0x80000000u }; // 1.5
	Fixed b = { -1, 0xc0000000u }; // -0.25
	Fixed result = FixedAdd(a, b);
	printf("%d.x%08" PRIx32 "\n", result.integer, result.fraction);
}