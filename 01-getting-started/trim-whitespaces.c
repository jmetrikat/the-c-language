#include <stdio.h>

/* a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
int main(void) {
    int c;
    char lastc = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ') {
            putchar(c);
        }
        lastc = c;
    }

	return 0;
}
