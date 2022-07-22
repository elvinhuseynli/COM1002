#include <stdio.h>

int main()
{
    int a = 0, counter = 0;
    float mean = 0.0, count = 0.0;
    
    
    while((scanf("%d", &a))!=EOF)
    {
        ++counter;
        if (a%3!=0 && a%5!= 0)
        {
            mean += a*a;
            count++;
        }
    }
    
    printf("%d ", counter);
    printf("%.2f", mean/count);

    
    

    return 0;
}
