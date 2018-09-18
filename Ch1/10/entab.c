#include <stdio.h>
#define TAB_WIDTH 4
#define MAXLINE 1000

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
  int i, j, t = 0;
  int nt = 0, ns = 0;
  for (i = 0, j = 0; i <= len && j < MAXLINE; ++i, ++j)
  {
    if (s[i] == ' ')
    {
      ns++;
      t++;
    }
    else if (s[i] == '\t')
    {
      t += (TAB_WIDTH - ((j - (ns + nt)) % TAB_WIDTH));
      nt++;
    }
    else if (t > 0)
    {
      int number_of_tabs = (t / TAB_WIDTH);
      t-= (TAB_WIDTH * number_of_tabs);
      j -= (t + number_of_tabs);
      while (number_of_tabs > 0)
      {
        s[j] = '#';
        number_of_tabs--;
        nt--;
        j++;
      }
      while (t > 0)
      {
        s[j] = '-';
        t--;
        ns--;
        j++;
      }
      nt = 0;
      ns = 0;
      t = 0;
      number_of_tabs = 0;
    }
    else
      s[j] = s[i];
  }
  s[j] = '\0';
}
