#include <stdio.h>
#include <stdlib.h>

static long long max3(long long x, long long y, long long z)
{
	long long m;

	m = x;
	if (y > m)
		m = y;
	if (z > m)
		m = z;
	return m;
}

int main(void)
{
	int n;
	int i;
	long long *wine;
	long long *dp;

	if (scanf("%d", &n) != 1)
		return 0;

	wine = (long long *)malloc(sizeof(long long) * (n + 1));
	dp = (long long *)malloc(sizeof(long long) * (n + 1));
	if (!wine || !dp)
	{
		free(wine);
		free(dp);
		return 0;
	}

	for (i = 1; i <= n; i++)
		scanf("%lld", &wine[i]);

	if (n == 1)
	{
		printf("%lld\n", wine[1]);
		free(wine);
		free(dp);
		return 0;
	}

	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (i = 3; i <= n; i++)
	{
		dp[i] = max3(dp[i - 1],
					dp[i - 2] + wine[i],
					dp[i - 3] + wine[i - 1] + wine[i]);
	}

	printf("%lld\n", dp[n]);

	free(wine);
	free(dp);
	return 0;
}
