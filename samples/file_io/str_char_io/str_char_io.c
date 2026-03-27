#include <stdio.h>

int main(void)
{
	FILE* f = fopen("example.txt", "w");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}
	fputs("Hello", f);
	fputc('!', f);
	fclose(f);

	f = fopen("example.txt", "r");
	if (f == NULL)
	{
		perror("fopen");
		return 1;
	}

	int c = fgetc(f);
	char buf[16];
	if (fgets(buf, sizeof(buf), f) == NULL)
	{
		perror("fgets");
		fclose(f);
		return 1;
	}
	fclose(f);

	printf("First char: %c\n", c);
	printf("Rest: %s\n", buf);
}