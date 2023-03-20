#include <ctype.h>
#include <stdio.h>

/* lower: convert input to lower case */
int main() {
    int c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));

    return 0;
}
