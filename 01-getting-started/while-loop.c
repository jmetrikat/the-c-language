#include <stdio.h>

/* Fahrenheit-Celsius table */
int main(void) {
	int lower = 0;
	int upper = 300;
	int step = 20;

	float celcius;
	float fahr = lower;

	while (fahr <= upper) {
		celcius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celcius);
		fahr += step;
	}

	return 0;
}
