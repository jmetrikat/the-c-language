#include <stdio.h>

/* function prototype */
int power(int base, int exponent);

/* calculate powers of 2 and -3 */
int main(void) {
    printf("n\tn^2\t  n^-3\n");
    printf("----------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("%d\t%3d\t%6d\n", i, power(2, i), power(-3, i));
	}

	return 0;
}

/* call by value: local variables are copies of the arguments */
int power(int base, int exponent) {
    int result;

    for (result = 1; exponent > 0; exponent--) {
        result *= base;
    }

	return result;
}
