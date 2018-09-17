#include <stdio.h>
#define TAB_WIDTH 4
#define MAXLINE 1000

int getline(char line[], int maxline);
void detab(char line[], int length);

main()
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
  {
    detab(line, len);
    printf("%s", line);
  }
  return 0;
}

int getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    if (c == '\n') {
      s[i] = c;
      ++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[], int len)
{
  int i, j, t;
  char scopy[len];

  for (i = 0; i < len; ++i)
    scopy[i] = s[i];

  for (i = 0, j = 0; i < len && j < MAXLINE; ++i, ++j)
  {
    if (scopy[i] == '\t')
    {
      int spaces = TAB_WIDTH - (j % TAB_WIDTH);
      for(t = spaces; t > 0; --t)
      {
        s[j++] = '-';
      }
      j--;
    }
    else
    {
      s[j] = scopy[i];
    }
  }
  s[j] = '\0';
}
