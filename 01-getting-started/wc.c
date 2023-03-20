#include <stdio.h>

/* count lines, words and characters in input */
int main(void) {
    int c;
    int nc = 0, nw = 0, nl = 0;
    int state = 1;

    while ((c = getchar()) != EOF) {
        if (c <= 32) {
            if (c == '\n')
                nl++;
            state = 1;
        } else if (state) {
            state = 0;
            nw++;
        }
        ++nc;
    }

    printf("%d %d %d \n", nl, nw, nc);
    return 0;
}
