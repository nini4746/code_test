// 백준 1932번: 삼각형에서 위에서 아래로 내려올 때 얻는 최대 합

#include <stdio.h>
#include <stdlib.h>

#define max(x,y) ((x) > (y) ? (x) : (y))

int main(void)
{
    int n;
    
    scanf("%d", &n);

    int **dp = calloc(n, sizeof(int *));
    int **cost = calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        dp[i] = calloc(i + 1, sizeof(int));
        cost[i] = calloc(i + 1, sizeof(int));
        for (int j = 0; j <= i; j++)
            scanf("%d", &cost[i][j]);
    }

    dp[0][0] = cost[0][0];
    
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = cost[i][0] + dp[i - 1][0];
        for (int j = 1; j < i; j++)
            dp[i][j] = cost[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        dp[i][i] = cost[i][i] + dp[i - 1][i - 1];
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < dp[n - 1][i])
            max = dp[n - 1][i];
    }
    printf("%d", max);
}
