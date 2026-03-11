#include <ctype.h>
#include <stdio.h>

typedef enum
{
	STATE_SPACE,
	STATE_WORD,
	STATE_NUMBER,
	STATE_ERROR
} State;

int main(void)
{
	State state = STATE_SPACE;

	int words = 0;
	int numbers = 0;
	int errors = 0;

	int c;

	while ((c = getchar()) != EOF)
	{

		if (isspace(c))
		{
			if (state == STATE_WORD)
				words++;
			else if (state == STATE_NUMBER)
				numbers++;
			else if (state == STATE_ERROR)
				errors++;

			state = STATE_SPACE;
			continue;
		}

		switch (state)
		{

		case STATE_SPACE:
			if (isalpha(c))
				state = STATE_WORD;
			else if (isdigit(c))
				state = STATE_NUMBER;
			else
				state = STATE_ERROR;
			break;

		case STATE_WORD:
			if (isdigit(c))
				state = STATE_ERROR;
			else if (!isalpha(c))
				state = STATE_ERROR;
			break;

		case STATE_NUMBER:
			if (isalpha(c))
				state = STATE_ERROR;
			else if (!isdigit(c))
				state = STATE_ERROR;
			break;

		case STATE_ERROR:
			if (isspace(c))
			{
				errors++;
				state = STATE_SPACE;
			}
			break;
		}
	}

	/* завершение последней последовательности */
	if (state == STATE_WORD)
		words++;
	else if (state == STATE_NUMBER)
		numbers++;
	else if (state == STATE_ERROR)
		errors++;

	printf("Words: %d\n", words);
	printf("Numbers: %d\n", numbers);
	printf("Errors: %d\n", errors);
}