#include <stdio.h>
#include <stdlib.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int main(void)
{
    int n;
    
    scanf("%d", &n);

    int *stair = (int *)malloc(sizeof(int) * n);
    if (!stair)
        return (1);
    for (int i = 0; i < n; i++)
        scanf("%d",&stair[i]);

    int *dp = (int *)malloc(sizeof(int) * n);

    dp[0] = stair[0];
    if (n == 1)
    {
        printf("%d", dp[n - 1]);
        return(0);

    }
    dp[1] = stair[0] + stair[1];
    if (n == 2)
    {
        printf("%d", dp[n - 1]);
        return(0);
    }
    dp[2] = MAX(stair[0] + stair[2], stair[1] + stair[2]);
    if (n == 3)
    {
        printf("%d", dp[n - 1]);
        return(0);
    }
    for (int i = 3; i < n; i++)
    {
        dp[i] = MAX(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
    }
    printf("%d", dp[n - 1]);
    return(0);
}
