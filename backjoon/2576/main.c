#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main (void)
{
    int a, sum, min;
    sum = 0;
    min = INT_MAX;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &a);
        if (a % 2 != 0)
        {
            sum += a;
            if (min > a)
                min = a;
        }
    }

    if(sum == 0)
        printf("-1");
    else
    {
        printf("%d\n%d", sum, min);
    }
}