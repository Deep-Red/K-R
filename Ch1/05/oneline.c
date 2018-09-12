#include <stdio.h>

#define WORD 1
#define NOT_WORD 0

/* print input one word per line */
main()
{
  int c, s = NOT_WORD;

  while ((c = getchar()) != EOF)
  {
    if ( c != ' ' && c != '\t' && c!= '\n')
    {
      s = WORD;
      putchar(c);
    }
    else
    {
      if (s)
      {
        s = NOT_WORD;
        putchar('\n');
      }
    }
  }
}
