#include <stdio.h>
#define TAB_WIDTH 4
#define MAXLINE 1000
#define IN_W 1
#define OUT_W 0

int getline(char line[], int maxline);
void entab(char line[], int length);

main()
{
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0)
  {
    entab(line, len);
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

void entab(char s[], int len)
{
  int i, j, w, spaces = 0, displacement = 0;
  int whitespace;
  char scopy[len];

  for (i = 0; i < len; ++i)
    scopy[i] = s[i];

  whitespace = ((s[i] == ' ') || (s[i] == '\t')) ? IN_W : OUT_W;

  for (i = 0, j = 0; i <= len && j < MAXLINE; ++i, ++j)
  {
    if (whitespace)
    {
      if (scopy[i] == ' ')
      {
        spaces++;
        displacement++;
      }
      else if (scopy[i] == '\t')
      {
        spaces += (TAB_WIDTH - (spaces % TAB_WIDTH));
        displacement++;
      }
      else
      {
        whitespace = OUT_W;
        j -= displacement;
        displacement = 0;
        for (w = 0; w < (spaces / TAB_WIDTH); w++)
          s[j++] = '#';
        for (w = 0; w < (spaces % TAB_WIDTH); w++)
          s[j++] = '-';
        i--;
        j--;
      }
    }
    else
    {
      if (scopy[i] == ' ' || scopy[i] == '\t')
      {
        whitespace = IN_W;
        spaces = 0;
        i--;
        j--;
      }
      else
        s[j] = scopy[i];
    }
  }
  s[j] = '\0';
}
