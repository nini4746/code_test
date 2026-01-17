#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *dp = calloc(n + 1, sizeof(int));
	int *prev = calloc(n + 1, sizeof(int));

	dp[1] = 0;
	prev[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		prev[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			prev[i] = i / 2;
		}

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
		{
			dp[i] = dp[i / 3] + 1;
			prev[i] = i / 3;
		}
	}

	printf("%d\n", dp[n]);

	while (n != 0)
	{
		printf("%d ", n);
		n = prev[n];
	}

	printf("\n");

	free(dp);
	free(prev);
	return 0;
}
