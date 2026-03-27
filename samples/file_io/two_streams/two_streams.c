#include <stdio.h>

int main(void)
{
	const char* filename = "test.txt";

	FILE* fw = fopen(filename, "w"); // поток записи
	FILE* fr = fopen(filename, "r"); // поток чтения

	if (!fw || !fr)
	{
		perror("fopen");
		return 1;
	}

	fprintf(fw, "Hello\n");

	char buf[64];
	if (fgets(buf, sizeof(buf), fr) == NULL)
	{
		printf("Read before fflush: EOF\n");
	}

	fflush(fw); // синхронизация

	rewind(fr); // вернуться в начало

	if (fgets(buf, sizeof(buf), fr) != NULL)
	{
		printf("Read after fflush: %s", buf);
	}

	fclose(fw);
	fclose(fr);
}