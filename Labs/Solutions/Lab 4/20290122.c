#include <stdio.h>
#include <stdlib.h>


int main()
{
    char a;
    while((scanf("%c", &a)!=EOF))
    {
        if (a == 'a' || a == 'e' || a == 'o' || a == 'u' || a == 'i')
        {
            a += 'A'-'a';
            printf("%c", a);
        }

        else if (a == 'Q' || a == 'W' || a == 'R' || a == 'T' || a == 'Y' || a == 'P' || a == 'S' || a == 'D' || a == 'F' || a == 'G' || a == 'H' || a == 'J' || a == 'K' || a == 'L' || a == 'Z' || a == 'X' || a == 'C' || a == 'V' || a == 'B' || a == 'N' || a == 'M')
        {
            a -= 'A'-'a';
            printf("%c", a);
        }
        else if (a == '1' || a == '2' ||a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '0')
        {
            continue;
        }
        else if (a == '\t' || a == ' ')
        {
            continue;
        }
        else
        {
            printf("%c", a);
        }
    }




    return 0;
}
