#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int number = 0;
struct Names
{
    char name[30];
};

void swapper(char array[number][30], int length, int i)
{
    int tmp = 0;
    if (i>0)
    {
        for (int k = i-1; k >= 0 && tmp == 0; k--)
        {
            int temp = 0;
            for (int j= 0; j < length && temp == 0; j++)
            {
                if (array[i][j] < array[k][j])
                {
                    temp = 1;
                    tmp = 1;
                }
                else if (array[i][j] > array[k][j])
                {
                    temp = 1;
                    char tempor[30];
                    strcpy(tempor, array[k]);
                    strcpy(array[k], array[i]);
                    strcpy(array[i], tempor);
                    i--;
                }
            }
        }        
    }
}

void capital_to_small(char array[30], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i]>='A' && array[i]<='Z')
        {
            array[i] = array[i] - 'A' + 'a';
        }
    }
}

int main()
{
    struct Names *names;
    if (scanf("%d", &number)==EOF) exit(0);
    char array[number][30];
    names = (struct Names*) malloc(number * sizeof(struct Names));
    for (int i = 0; i < number; i++)
    {
        scanf("%s", (names+i)->name);
        strcpy(array[i], (names+i)->name);
        capital_to_small(array[i], strlen(array[i]));
        swapper(array, strlen(array[i]), i);
    }
    for (int i = 0; i < number; i++)
    {
        printf("%s\n", array[i]);
    }
    return 0;
}