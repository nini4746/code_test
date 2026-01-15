#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    long long r, k, m, j;

    char s1[32], s2[32], s3[32];

    scanf("%s %s %s", s1, s2, s3);

    r = atoll(s1);
    k = atoll(s2);
    m = atoll(s3);

    j = m / k;

    while (j > 0 && r > 0)
    {
        r >>= 1;
        j--;
    }

    printf("%lld",r);
}