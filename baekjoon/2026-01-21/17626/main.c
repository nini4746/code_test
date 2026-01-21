// 백준 17626번: 자연수를 네 제곱수 합으로 표현할 때 최소 항 개수

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *dp = malloc((n + 1) * sizeof(int));

	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			int sq = j * j;
			if (dp[i] > dp[i - sq] + 1)
				dp[i] = dp[i - sq] + 1;
		}
	}

	printf("%d\n", dp[n]);
	free(dp);
	return 0;
}
