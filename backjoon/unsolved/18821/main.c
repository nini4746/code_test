#include <stdio.h>

int main(void)
{
    int t, n;

    scanf("%d", &n);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        if(n % 2 == 0)
            printf("E\n");
        else
            printf("O\n");
    }
}