#include <stdio.h>

/* use array to count digits, white space, other characters */
int main(void) {
    int c;
	int ndigits[10];
	int nwhite = 0, nother = 0;

	for (int i = 0; i < 10; i++) {
		ndigits[i] = 0;
	}

	while((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			ndigits[c - '0']++;
		else if (c <= 32)
			nwhite++;
		else
			nother++;
	}
	printf("digits =");
	for (int i = 0; i < 10; i++) {
		printf(" %d", ndigits[i]);
	}

	printf("\nwhite space = %d\nother = %d\n", nwhite, nother);
    return 0;
}
