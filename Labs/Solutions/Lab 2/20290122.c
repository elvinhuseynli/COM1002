#include <stdio.h>

int main()
{
    int n1=0, n2=0, n3=0, s=0, x=0, m=0;
    float a = 0.0;
    char operation;
    scanf("%d %d %d %c", &n1, &n2, &n3, &operation);
    if (operation == 's')
    {
        s = n1 + n2 + n3;
        printf("%d", s);
    }
    else if (operation == 'a')
    {
        a = (n1+n2+n3)/3.0;
        printf("%.2f", a);
    }
    else if (operation == 'x')
    {
        if (n1>=n2 && n1>=n3)
        {
            x = n1;
            printf("%d", x);
        }
        else if (n2>=n1 && n2>=n3)
        {
            x = n2;
            printf("%d", x);
        }
        else
        {
            printf("%d", n3);
        }
    }
    else if (operation == 'm')
    {
        if (n1<=n2 && n1<=n3)
        {
            m = n1;
            printf("%d", m);
        }
        else if (n2<=n1 && n2<=n3)
        {
            m = n2;
            printf("%d", m);
        }
        else
        {
            printf("%d", n3);
        }
    }



    return 0;
}
