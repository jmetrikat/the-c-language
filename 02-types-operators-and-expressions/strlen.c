#include <stdio.h>

/* stringlen: return length of string s */
int stringlen(char *s) {
    int n;

    for (n = 0; *s != '\0'; s++) {
        n++;
    }

    return n;
}

int main(void) {
    char *s = "Hello World";
    printf("%d\n", stringlen(s));
}
