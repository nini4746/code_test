// 백준 1149번: 인접한 집은 다른 색으로 칠하며 전체 최소 비용을 구하기

#include <stdio.h>
#include <stdlib.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

int main(void)
{
    int n;

    scanf("%d", &n);

    int **dp = calloc(n, sizeof(int *));
    int **cost = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        cost[i] = calloc(3, sizeof(int));
        dp[i] = calloc(3, sizeof(int));
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
    }

    printf("%d", min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]));
}
