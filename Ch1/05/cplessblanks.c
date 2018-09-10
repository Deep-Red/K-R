#include <stdio.h>

/* copy input to output replacing each string of blanks with single blank */

main()
{
  int c, b;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
      b ++;
    else
    {
      if (b > 0)
        printf(" ");
      putchar(c);
      b = 0;
    }
  }
}
