#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int n;

    scanf("%d", &n);

    int size[6] = {0};

    for (int i = 0; i < 6; i++)
        scanf("%d", &size[i]);
    
    int t, q;

    scanf("%d %d", &t, &q);

    int sum = 0;
    
    for (int i = 0; i < 6; i++)
    {
        sum += size[i] / t;
        
        if (size[i] % t != 0)
            sum++;
    }

    printf("%d\n",sum);
    printf("%d %d",n / q, n % q);
}