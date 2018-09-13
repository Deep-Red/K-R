#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);
void remtrwh(char line[], int maxline);

/* print longest input line */
main()
{
  int len;  /* current line length */
  int max;  /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    {
      remtrwh(line, len);
      printf("%s", line);
    }
  return 0;
}

/* getline: read a line into s, return length */
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

void remtrwh(char s[], int len)
{
  int i = len;

  while (s[i] <= ' ')
    --i;
  s[i+1] = '\n';
  s[i+2] = '\0';
}
