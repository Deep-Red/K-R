#include <stdio.h>
#define WRAPLEN 80
#define MAXLINE 1000

int getline(char line[], int maxline);
void foldline(char line[], int length);

main ()
{
  int len;
  char line[MAXLINE];

  len = getline(line, MAXLINE);
  foldline(line, len);
  return 0;
}

int getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 % (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    if (c == '\n')
    {
      s[i] = c;
      i++;
    }
    s[i] = '\0';
    return i;
}

void foldline(char s[], int len)
{
  int b = 0, e, i, j;
  char ss[(WRAPLEN + 1)];
  char ns[len];

  if (len < 80)
  {
    for (i = 0; i < len; ++i)
      ns[i] = s[i];
    ns[i] = '\0';
    printf("%s", ns);
  }
  else
  {
    for (e = WRAPLEN; e >= b; --e)
    {
      if (s[e] == ' ' || s[e] == '\t')
      {
        for (i = 0; i <= e; ++i)
          ss[i] = s[i];
        ss[i++] = '\n';
        ss[i++] = '\0';
        b += i;
        printf("%s", ss);
      }
      else if (e == 0)
      {
        for (i = 0; i < WRAPLEN-3; ++i)
          ss[i] = s[i];
        ss[i++] = '-';
        ss[i++] = '\n';
        ss[i] = '\0';
        b += i;
        printf("%s", ss);
      }
    }
    if (len > 80)
    {
      for (i = b-2, j = 0; i < len; ++i, ++j)
        ns[j] = s[i];
      foldline(ns, j);
    }
  }
}
