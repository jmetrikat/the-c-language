#include <stdio.h>

/* a program to count blanks, tabs, and newlines */
int main() {
    int c;
    int nl = 0;
    int nt = 0;
    int nb = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++nb;
    }

    printf("%d %d %d\n", nl, nt, nb);
	return 0;
}
