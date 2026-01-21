// 백준 10093번: 주어진 두 수 사이의 모든 정수 개수와 목록 출력

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long a, b;
    long long lo, hi;
    long long cnt;
    long long i;

    scanf("%lld %lld", &a, &b);

    lo = (a < b) ? a : b;
    hi = (a < b) ? b : a;

    cnt = hi - lo - 1;
    if (cnt < 0)
        cnt = 0;

    printf("%lld\n", cnt);

    for (i = lo + 1; i < hi; i++)
    {
        printf("%lld", i);
        if (i + 1 < hi)
            printf(" ");
    }
    printf("\n");

    return (0);
}
