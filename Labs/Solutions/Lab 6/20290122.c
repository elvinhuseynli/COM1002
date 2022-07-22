#include <stdio.h>
#include <math.h>

char deleting_indexed_items(char or[101], int index, int *counter)
{
    for (int i = index; i < *counter; i++)
    {
        or[i] = or[i+1];

    }
    (*counter)--;
    

}

int main()
{
    char array[101];
    char a;
    char result;
    int counter = 0, count = 0, integer = 0;
    int int_array[101];
    scanf("%c", &a);
    while (a != ' ')
    {
        array[counter] = a;
        counter++;
        scanf("%c", &a);
    }
    /*
    for (int i = 0; i < counter; i++)
    {
        printf("%c\t", array[i]);
    }
    printf("\n");*/

    scanf("%d", &integer);
    while (integer != -1)
    {
        int_array[count] = integer;
        count++;
        scanf("%d", &integer);
    }

    for (int i = 0; i < count; i++)
    {
        if (int_array[i]<=counter){
            result = deleting_indexed_items(array, int_array[i], &counter);
        }
        else
        {
            continue;
        }
        
    }
    for (int i = 0; i < counter; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");

    /*for (int i = 0; i < count; i++)
    {
        printf("%d\t", int_array[i]);
    }*/
    
    
    
    

    return 0;
}