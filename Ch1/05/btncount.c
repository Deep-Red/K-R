#include <stdio.h>

/* count blanks, tabs, and newlines in input */
main()
{
    int c, b, t, n;

    b, t, n = 0;
    while ((c = getchar()) != EOF)
    {
      if (c == ' ')
        ++b;
      if (c == '\t')
        ++t;
      if (c == '\n')
        ++n;
    }

    printf("Blanks: %d, Tabs: %d, Newlines: %d\n", b, t, n);
}
