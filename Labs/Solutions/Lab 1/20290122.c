#include <stdio.h>

int main()
{
        float velocity, time, height, g=10;
        scanf("%f", &velocity);
        time = velocity/g;
        height = 0.5*velocity*time;
        printf("%.2f m\n", height);
 
        return 0;
}
