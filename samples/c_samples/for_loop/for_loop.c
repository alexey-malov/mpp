#include <stdio.h>

int main() {
	printf("Numbers from 1 to 100 with step 2:\n");

	for (int i = 1; i <= 100; i += 2) {
		printf("%d\n", i);
	}

	return 0;
}
