// 백준 9095번: 1,2,3을 더해 n을 만드는 방법의 수

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    int *dp = (int *)malloc(sizeof(int) * 11);

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i < 11; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n",dp[a - 1]);
    }
    return 0;
}

