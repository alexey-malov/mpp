#include <stdint.h>
#include <stdio.h>

int main(void)
{
	uint32_t a[5] = { 10, 20, 30, 40, 50 };
	uint32_t b[5];

	FILE* f = fopen("numbers.bin", "w+b");
	fwrite(a, sizeof(uint32_t), 5, f);

	fseek(f, 3 * sizeof(uint32_t), SEEK_SET);
	uint32_t x = 42;
	fwrite(&x, sizeof(uint32_t), 1, f);

	fseek(f, 0, SEEK_SET);
	fread(b, sizeof(uint32_t), 5, f);
	fclose(f);

	printf("Modified array: ");
	for (size_t i = 0; i < 5; ++i)
	{
		printf("%u ", b[i]);
	}
	printf("\n");
}