#include <stdio.h>

int ftoc(int fahr);

/* print Fahrenheit-Celsius table using a function */
main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; /* lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  fahr = lower;

  printf(" °F     °C\n");
  while (fahr <= upper) {
    celsius = ftoc(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}

int ftoc(int fahr)
{
  int r;
  r = (5.0/9.0) * (fahr - 32.0);
  return r;
}
