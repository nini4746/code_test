// 백준 33572번: 카드 값에서 1을 뺀 합이 m 이상이면 DIMI, 아니면 OUT

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long n,m;

    scanf("%lld %lld",&n,&m);

    long long *arr = calloc(n, sizeof(long long));
    if (!arr)
        return (1);

    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        total += arr[i] - 1;
    }

    if (total < m)
        printf("OUT");
    else
        printf("DIMI");
    free(arr);
    return (0);
}
