#include <stdio.h>

#define MAXCHAR 5000
#define IN 1
#define OUT 0


main()
{
  int npar = 0, nbck = 0, nbcs = 0, c = 0;
  int comm = OUT, ccon = OUT, str = OUT;

  while ((c = getchar()) != EOF)
  {
    if (c == '[')
      nbck++;
    else if (c == '{')
      nbcs++;
    else if (c == '(')
      npar++;
    else if (c == ']')
      nbck--;
    else if (c == '}')
      nbcs--;
    else if (c == ')')
      npar--;
    else if (c == '"')
    {
      str = IN;
      while (str && (c = getchar()) != EOF)
      {
        if (c == '\\')
          (c = getchar());
        else if (c == '"')
          str = OUT;
      }
    }
    else if (c == '\'')
    {
      ccon = IN;
      while (ccon && (c = getchar()) != EOF)
      {
        if ((c = getchar()) == '\\')
          c = getchar();
        else if ((c = getchar()) == '\'')
          ccon = OUT;
      }
    }
    else if (c == '/')
    {
      if ((c = getchar()) == '*')
      {
        comm = IN;
        while (comm && (c = getchar()) != EOF)
        {
          if ((c = getchar()) == '*')
          {
            if ((c = getchar()) == '/')
              comm = OUT;
            else
              ungetc(c, stdin);
          }
        }
      }
      else
        ungetc(c, stdin);
    }
  }
  if (npar > 0)
    printf("%s", "Unmatched \"(\"\n");
  if (npar < 0)
    printf("%s", "Unmatched \")\"\n");
  if (nbcs > 0)
    printf("%s", "Unmatched \"{\"\n");
  if (nbcs < 0)
    printf("%s", "Unmatched \"}\"\n");
  if (nbck > 0)
    printf("%s", "Unmatched \"[\"\n");
  if (nbck < 0)
    printf("%s", "Unmatched \"]\"\n");
  if (comm != OUT)
    printf("%s", "Unclosed comment\n");
  if (ccon != OUT)
    printf("%s", "Unclosed character constant\n");
  if (str != OUT)
    printf("%s", "Unclosed string\n");
}
