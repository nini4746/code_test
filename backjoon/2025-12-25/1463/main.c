#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    int dp[1000001];
    int i, best;

    dp[1] = 0;

    i = 2;

    while (i <= n)
    {
        best = dp[i - 1] + 1;
        printf("%d",best);

        if (i % 2 == 0)
        {
            if (dp[i / 2] + 1 < best)
                best = dp[i / 2] + 1;
            printf(" %d",best);
        }
        if (i % 3 == 0)
        {
            if (dp[i / 3] + 1 < best)
                best = dp[i / 3] + 1;
            printf(" %d",best);
        }

        dp[i] = best;
        i++;
        printf("\n%d %d\n\n",best, i);
    }

    printf("%d", dp[n]);
    return (0);
}