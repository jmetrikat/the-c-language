#include <stdio.h>

/* rudimentary calculator */
int main(void) {
    double sum = 0;
    double v = 0;

    while (scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);
    return 0;
}
