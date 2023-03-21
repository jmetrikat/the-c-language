#include <stdio.h>

/* atoi: convert s to integer */
int atoi(char *s) {
    int n = 0;

    for (int i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}

int main(void) {
    char *s = "12345";
    printf("%d\n", atoi(s));
}
