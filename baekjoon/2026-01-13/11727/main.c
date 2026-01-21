// 백준 11727번: 2×n 보드를 1×2, 2×1, 2×2 타일로 채우는 경우의 수

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int n;

	scanf("%d", &n);

	int *dp = calloc(n + 2, sizeof(int));

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i < n; i++)
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007; 

	printf("%d", dp[n - 1]);
	free(dp);
}
