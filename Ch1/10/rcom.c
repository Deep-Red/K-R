#include <stdio.h>
#define MAXCHAR 5000

main ()
{
  int c, i, comm = 0, ccon = 0, str = 0;
  char out[MAXCHAR];

  while ((c = getchar()) != EOF)
  {
    if (!str && !comm && !ccon)
    {
      if (c == '"')
      {
        str = 1;
        out[i] = c;
      }
      else if (c == '\'')
      {
        ccon = 1;
        out[i] = c;
      }
      else if (c == '/')
      {
        if (getchar() == '*')
        {
          i--;
          comm = 1;
          while (comm && (c = getchar()) != EOF)
          {
            if ((c = getchar()) == '*')
              if ((c = getchar()) == '/')
                comm = 0;
          }
        }
        else
          out[i] = c;
      }
      else
        out[i] = c;
    }
    else if (ccon)
    {
      if (c == '\'')
        ccon = 0;
      out[i] = c;
    }
    else if (str)
    {
      if (c == '"')
        str = !str;
      out[i] = c;
    }
    else
      out[i] = c;
    i++;
  }
  out[i] = '\0';
  printf("%s", out);
}
