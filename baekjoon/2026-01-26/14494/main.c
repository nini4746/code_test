#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int m;
	long long **dp;
	int i;
	int j;
	const long long MOD = 1000000007LL;

	scanf("%d %d", &n, &m);

	dp = calloc(n, sizeof(long long *));
	for (i = 0; i < n; i++)
		dp[i] = calloc(m, sizeof(long long));

	for (i = 0; i < n; i++)
		dp[i][0] = 1;
	for (j = 0; j < m; j++)
		dp[0][j] = 1;

	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
	}

	printf("%lld", dp[n - 1][m - 1]);

	for (i = 0; i < n; i++)
		free(dp[i]);
	free(dp);

	return (0);
}
