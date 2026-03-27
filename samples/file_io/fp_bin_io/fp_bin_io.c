#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* f = fopen("pi.bin", "wb");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}
	const double pi = 3.14159265358979323846;
	if (fwrite(&pi, sizeof(pi), 1, f) != 1)
	{
		perror("fwrite");
		goto err;
	}
	fclose(f);

	f = fopen("pi.bin", "rb");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}
	double pi1;
	if (fread(&pi1, sizeof(pi1), 1, f) != 1)
	{
		perror("fread");
		goto err;
	}
	fclose(f);

	printf("pi = %.15f\n", pi);
	printf("pi1 = %.15f\n", pi1);
	printf("memcmp: %d\n", memcmp(&pi1, &pi, sizeof(pi)));
	return 0;

err:
	fclose(f);
	return 1;
}