#include <stdio.h>
#include <stdlib.h>
/*
int sum_of_digits(int p)
{
    int another=0, newer=0;
    while (p>0)
    {
	printf("%d", p);
        another = p %10;
        newer += another;
        p/=10;
	//printf("%d ", p);
    }
    return newer;
}
*/


int main()
{
    int x=0, result=0, number=0;
    while((scanf("%d", &x))!= EOF)
    {
	int newer=0, another=0;
	//printf("%d\n", x);
        number++;
        if((x >0) &&( x == 2 || x==3 || x%2!=0))
        {
	    
	    if (x == 2 || x==3)
	    {
	        printf("%d ", x);
	    }
	    //printf("%d ", x);
            for(int i=3; i < x; i ++)
            {
                if (x%i==0)
                {
                    break;
                }
                else if(x%i!=0 && i == x-1)
		{
		    //printf("%d ", x);
		    while (x>0)
		    {
			//printf("%d ", x);
			another = x %10;
			newer += another;
			x/=10;
		    }
		    printf("%d ", newer);
                }

            }
        }
    }
    printf("%d", number);



    return 0;
}

