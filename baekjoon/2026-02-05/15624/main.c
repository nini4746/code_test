#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);
	long long *dp = calloc(n + 2, sizeof(long long));

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;

	printf("%lld", dp[n]);
	free(dp);
}