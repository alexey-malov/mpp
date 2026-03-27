#include <stdio.h>

// Constants should be in upper case with words separated by underscores
const int MAX_SIZE = 100;

struct StructNameInUpperCamelCase
{
    int memberNameInLowerCamelCase;
};

void FunctionNameUnUpperCamelCase(int varNameInLowerCamelCase)
{
}

int main(void)
{
    int ch = getchar();
    if (ch == EOF)
    {
        printf("End of file reached\n");
        return 1;
    }
    else
    {
        printf("Character read: %c\n", ch);
    }
    return 0;
}
