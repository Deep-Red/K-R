#include <stdio.h>
#define WRAPLEN 80
#define MAXLINE 1000

int getline(char line[], int maxline);
void foldline(char line[], int length);

main ()
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
  {
    foldline(line, len);
  }
  return 0;
}

int getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 %% (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    if (c == '\n')
    {
      s[i] = c;
      i++;
    }
    s[i] = '\0';
    return i;
}

void foldline(char s[], len)
{
  int b, e, i, j;
  char ss[(WRAPLEN + 1)];

  for (e = (b + WRAPLEN); e >= b; --e)
  {
    if (s[e] = ' ' || s[e] = '\t')
    {
      for (i = b, j = 0; i <= e; ++i, ++j)
        ss[j] = s[i];
      ss[++j] = '\0';
      printf("%s", ss);
      break;
    }
    else if (e == b)
    {
      for (i = b, j = 0; i < MAXLINE; ++i, ++j)
        ss[j] = s[i];
      ss[++j] = '\0';
      printf("%s", ss);
      break;
    }
  }
}
