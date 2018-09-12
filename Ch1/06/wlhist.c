#include <stdio.h>

#define WORD 1
#define NOT_WORD 0
#define MAX_LEN 100

/* print histogram of word lengths in input */
int main()
{
  int c, s = NOT_WORD, i = 0, j;
  int wl[MAX_LEN];
  int maxlen = 0, maxfreq = 0;

  for (i = 0; i < MAX_LEN; i++)
    wl[i] = 0;

  /* Track width of histogram */
  int set_maxlen(int i)
  {
    return (i >= maxlen) ? i : maxlen;
  }

  /* Find maximum height of histogram */
  int set_maxfreq(int maxlen)
  {
    for (int i = 0; i <= maxlen; ++i)
    {
      if (maxfreq < wl[i])
      maxfreq = wl[i];
    }
    return maxfreq;
  }

  /* Receive user input */
  i = 0;
  while ((c = getchar()) != EOF)
  {
    if (c != ' ' && c != '\t' && c != '\n')
    {
      s = WORD;
      i++;
    }
    else
    {
      if(s)
      {
        s = NOT_WORD;
        wl[i]++;
        maxlen = set_maxlen(i);
        i = 0;
      }
    }
  }

  maxfreq = set_maxfreq(maxlen);

  /* Print histogram */
  putchar('\n');
  for (j = maxfreq; j > 0; j--)
  {
    for (i = 0; i <= maxlen; i++)
    {
        if (j <= wl[i])
          putchar('#');
        else
          putchar(' ');
    }
    putchar('\n');
  }

  /* print legend */
  putchar(' ');
  for (i = 1; i <= maxlen, i <= 9; i++)
    printf("%d", i);
  putchar('\n');
}
