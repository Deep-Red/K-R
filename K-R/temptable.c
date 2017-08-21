#include <stdio.h>

/* print Farenheit - Celsius table for f = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit of temperature scale */
	step = 20; /* step size */

	celsius = lower;
	
	printf(" \xf8");
	printf("C    \xf8");
	printf("F\n");

	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%3.0f%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}