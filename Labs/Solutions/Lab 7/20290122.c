#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int a = 0, b=0;
    char array[100][30];
    char wanted[100][30];
    int point[100];
    int count=1;
    scanf("%s", array[a]);
    
    while (count)
    {
        if (array[a][0] == 'E' && array[a][1] == 'N' && array[a][2] == 'D')
        {
            break;
        }
        else
        {
            scanf("%d", &point[a]);
            a++;
            scanf("%s", array[a]);
        }
               
    }

    
    while (scanf("%s", wanted[b])!=EOF)
    {
        for (int i = 0; i < a; i++)
        {
            if (strcmp(wanted[b], array[i])==0)
            {
                printf("%s %d\n", array[i], point[i]);
            }
        }
        b++;
    }
    





    
    
    
    
    
    


    return 0;
}