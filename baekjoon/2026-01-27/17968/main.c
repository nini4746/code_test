#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	scanf("%d", &N);

	int *dp = calloc(N + 1, sizeof(int));

	dp[0] = 1;
	if (N >= 1)
		dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int forbid[1000];
		int fcnt = 0;

		for (int k = 1; i - 2 * k >= 0; k++)
		{
			int v = 2 * dp[i - k] - dp[i - 2 * k];
			if (v > 0)
				forbid[fcnt++] = v;
		}

		int x = 1;
		int ok;

		while (1)
		{
			ok = 1;
			for (int j = 0; j < fcnt; j++)
			{
				if (forbid[j] == x)
				{
					ok = 0;
					break;
				}
			}
			if (ok)
				break;
			x++;
		}

		dp[i] = x;
	}

	printf("%d\n", dp[N]);

	free(dp);
	return 0;
}
