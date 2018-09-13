#include <stdio.h>
#define MAXLINE 1000 /* limit line input size */

int getline(char line[], int maxline);
void reverse(char s[], int len);

/* reverse input line by line */
main()
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
  {
    reverse(line, len);
    printf("%s\n", line);
  }
  return 0;
}

int getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}

void reverse(char s[], int len)
{
  int start = 0;
  len--;
  while (start < len)
  {
    s[start] ^= s[len];
    s[len] ^= s[start];
    s[start] ^= s[len];

    ++start;
    --len;
  }
}
