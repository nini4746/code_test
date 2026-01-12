#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n, l;

    scanf("%d %d", &n, &l);

    for (int i = 0; i < l - 1; i++)
    {
        printf("1");
    }
    printf("%d", n);
}
