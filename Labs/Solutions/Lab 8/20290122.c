#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Patients
{
    char array[15];
    char bcts[4];
}patients[100];

void Capital_small_converter(char arr[15], int length)
{
    char changed;
    for (int i = 0; i < length; i++)
    {
        if (arr[i]<='Z' && arr[i]>='A')
        {
            changed = arr[i] - ('A'-'a');
            arr[i] = changed;
        }
    }
}

void name_checker(char arr[15], int count)
{
    int flag = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(patients[i].array, arr) == 0)
        {
            printf("%s %s\n", arr, patients[i].bcts);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("%s %s\n", arr, "0+");
    }
}

int main()
{
    char needed_names[100][15];
    int counter = 0, count=0;
    char a[5] = "start";
    char b[4] = "end";
    while (scanf("%s", patients[counter].array)!=EOF)
    {
        if (strcmp(a, patients[counter].array)==0)
        {
            break;
        }
        Capital_small_converter(patients[counter].array, strlen(patients[counter].array));
        scanf(" %s", patients[counter].bcts);
        counter++;        
    }/*
    for (int i = 0; i < counter; i++)
    {
        printf("%s\t%s\n", patients[i].array, patients[i].bcts);
    }
    */
    while (scanf("%s", needed_names[count])!=EOF)
    {
        if (strcmp(b, needed_names[count]) == 0)
        {
            break;
        }
        Capital_small_converter(needed_names[count], strlen(needed_names[count]));
        name_checker(needed_names[count], counter);
        count++;
    }
    
    
    

    
    return 0;
}