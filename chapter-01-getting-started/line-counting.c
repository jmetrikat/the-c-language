#include <stdio.h>

/* count lines in input */
int main() {
	char c;
	int counter = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++counter;
	}

	printf("%d\n", counter);
	return 0;
}
