// 백준 13699번: 주어진 점화식 t[n]을 DP로 계산

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;

	scanf("%d", &n);
	long long *dp = calloc(n + 5, sizeof(long long));

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int k = i - 1;
		for (int j = 0; j < i;)
		{
			dp[i] += dp[k--] * dp[j++];
		}
	}

	printf("%lld", dp[n]);
	free(dp);
}
