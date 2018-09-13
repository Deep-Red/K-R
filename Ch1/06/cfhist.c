#include <stdio.h>

#define MAX_CHARS 300

/* print histogram of word lengths in input */
int main()
{
  int c, i = 0, j = 0;
  int c_arr[MAX_CHARS];
  int highest_char = 0, maxfreq = 0;

  for (i = 0; i < MAX_CHARS; i++)
    c_arr[i] = 0;

  /* Track width of histogram */
  int set_highest_char(int i)
  {
    return (i >= highest_char) ? i : highest_char;
  }

  /* Find maximum height of histogram */
  int set_maxfreq(int highest_char)
  {
    for (int i = 0; i <= highest_char; ++i)
    {
      if (maxfreq < c_arr[i])
      maxfreq = c_arr[i];
    }
    return maxfreq;
  }

  /* Receive user input */
  while ((c = getchar()) != EOF)
    {
      c_arr[c] += 1;
      highest_char = set_highest_char(c);
    }

  maxfreq = set_maxfreq(highest_char);

  /* Print histogram */
  putchar('\n');
  for (j = maxfreq; j > 0; j--)
  {
    for (i = 0; i <= highest_char; i++)
    {
        if (j <= c_arr[i])
          putchar('#');
        else
          putchar(' ');
    }
    putchar('\n');
  }

  /* print legend */
  putchar(' ');
  for (i = 1; i < ' '; i++)
    printf(" ");
  for (i = ' '; i <= highest_char; i++)
    printf("%c", i);
  putchar('\n');
}
