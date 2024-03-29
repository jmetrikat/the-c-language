#include <stdio.h>

/* avoid magic numbers, instead use "#define name replacement" */
#define LOWER 	0
#define UPPER 	300
#define STEP 	20

/* Fahrenheit-Celsius table using for-loop */
int main(void) {
	for (int fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}

	return 0;
}
