// 백준 11050번: nCk 이항 계수를 계산

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, k;

    scanf("%d %d", &n, &k);

    int i1 = 1;
    int i2 = 1;
    int i3 = 1;

    for (int i = 2; i <= n; i++)
        i1 *= i;
    for (int i = 2; i <= k; i++)
        i2 *= i;
    for (int i = 2; i <= n - k; i++)
        i3 *= i;

    printf("%d", i1/(i2 * i3));
}
