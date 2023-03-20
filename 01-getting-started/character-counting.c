#include <stdio.h>

/* count characters in input */
int main(void) {
    char counter;

    for (counter = 0; getchar() != EOF; counter++) {
        ;
    }
    printf("%d\n", counter);

    return 0;
}
