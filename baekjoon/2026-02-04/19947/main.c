#include <stdio.h>
#include <stdlib.h>

static long long	maxll(long long a, long long b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	long long	H;
	int			Y;
	long long	*dp;
	int			i;

	if (scanf("%lld %d", &H, &Y) != 2)
		return (0);

	dp = (long long *)calloc((size_t)Y + 1, sizeof(long long));
	if (!dp)
		return (0);

	dp[0] = H;
	for (i = 1; i <= Y; i++)
	{
		dp[i] = maxll(dp[i], dp[i - 1] * 105 / 100);
		if (i >= 3)
			dp[i] = maxll(dp[i], dp[i - 3] * 120 / 100);
		if (i >= 5)
			dp[i] = maxll(dp[i], dp[i - 5] * 135 / 100);
	}

	printf("%lld\n", dp[Y]);
	free(dp);
	return (0);
}
