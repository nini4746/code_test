#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *arr;
    int b, c;
    scanf("%d", &n);

    arr = calloc(n, sizeof(int));
    if (!arr)
        return (1);
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    scanf("%d %d",&b, &c);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum++;
        arr[i] -= b;
        if (arr[i] <= 0)
            continue;
        if (arr[i] % c != 0)
            sum++;
        sum += arr[i] / c;
    }
    printf("%lld", sum);
    return (0);
}