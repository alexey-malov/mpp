#include <stdio.h>

int main(void)
{
	// Для записи текста в файл, необходимо открыть его в режиме "w" (write).
	FILE* f = fopen("file.txt", "w");
	if (f == NULL)
	{
		// Если fopen возвращает NULL, значит произошла ошибка при открытии файла.
		perror("Failed to open file");
		return 1;
	}
	fprintf(f, "I love C!\n");
	fprintf(f, "How do you do?\n");
	fclose(f);

	f = fopen("file.txt", "r"); // Проверка ошибок пропущена для экономии места
	char buf[64];
	if (fgets(buf, sizeof(buf), f) != NULL)
	{
		printf("First line: %s", buf);
	}
	if (fgets(buf, sizeof(buf), f) != NULL)
	{
		printf("Second line: %s", buf);
	}
	fclose(f);
}