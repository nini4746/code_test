#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;

	scanf("%d", &n);
	
	long long *dp = calloc(n, sizeof(long long));

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <=n; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	printf("%lld", dp[n]);
}
