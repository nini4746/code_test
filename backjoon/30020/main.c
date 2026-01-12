#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    if (a <= 2 * b && a >= b + 1)
    {
        printf("YES\n");
        printf("%d\n", a - b);
        while (a != (b + 1))
        {
            printf("aba\n");
            a -= 2;
            b -= 1;
        }
        printf("a");
        for (int i = 0; i < b; i++)
            printf("ba");
    }
    else
        printf("NO");

}
