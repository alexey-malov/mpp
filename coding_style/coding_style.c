#include <stdio.h> // Leave at least one empty line after the include block.

// Constants should be in upper case with words separated by underscores
const int MAX_SIZE = 100;

// Struct name should be in UpperCamelCase
struct StructNameInUpperCamelCase
{
	int memberNameInLowerCamelCase;
};

enum ParserState
{
	// В разных enum-ах не допускается пересечение имен значений,
	// поэтому общепринятой практикой является добавление префикса (связанного с именем enum-а)
	// Здесь используется префикс PS - сокращение от Parser State
	PS_IDLE,
	PS_WITHIN_WORD,
	PS_BETWEEN_WORDS,
};

// Function name should be in UpperCamelCase
void FunctionNameUnUpperCamelCase(int varNameInLowerCamelCase)
{
	const int localMaxSize = 10; // Local const name should be in lowerCamelCase
	if (varNameInLowerCamelCase > localMaxSize) // The opening bracket is at the next line
	{
		printf("%d is grater than %d\n", varNameInLowerCamelCase, localMaxSize);
	}
	else
	{
		printf("%d is less or equal to %d\n", varNameInLowerCamelCase, localMaxSize);
	}
}

void PrintArray(const int* arr, int size) // The pointer symbol "*" is always close to the data type, not to the variable
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int numbers[] = { 10, 20, 30, 40, 50 };
	int* ptr = numbers;

	PrintArray(ptr, 5);

	FunctionNameUnUpperCamelCase(5);
	return 0;
}
