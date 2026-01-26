#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int *dp;
	int coin[4];
	int i;
	int j;
	int min;

	if (scanf("%d", &n) != 1)
		return (0);

	coin[0] = 1;
	coin[1] = 2;
	coin[2] = 5;
	coin[3] = 7;

	dp = malloc((n + 1) * sizeof(int));
	if (!dp)
		return (0);

	dp[0] = 0;

	i = 1;
	while (i <= n)
	{
		dp[i] = 1000000000;
		j = 0;
		while (j < 4)
		{
			if (i - coin[j] >= 0)
			{
				min = dp[i - coin[j]] + 1;
				if (min < dp[i])
					dp[i] = min;
			}
			j++;
		}
		i++;
	}

	printf("%d\n", dp[n]);

	free(dp);
	return (0);
}
