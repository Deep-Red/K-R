#include <stdio.h>

/* copy input to output replacing each string of blanks with single blank */

main()
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
  }
}
