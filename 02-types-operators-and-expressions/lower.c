#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    } else {
        return c;
    }
}

int main(void) {
    char *s = "HELLO WORLD!";

    printf("%s\n", s);

    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", lower(s[i]));
    }
    printf("\n");

    return 0;
}
