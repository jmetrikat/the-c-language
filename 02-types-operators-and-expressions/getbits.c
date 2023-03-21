#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main(void) {
    unsigned x = 0b10101010;
    printf("%d\n", getbits(x, 4, 3));

    return 0;
}
