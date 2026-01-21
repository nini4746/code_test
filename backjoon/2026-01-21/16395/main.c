// 백준 16395번: 파스칼 삼각형 n번째 줄의 k번째 수 출력

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	long long **dp = calloc(n, sizeof(long long *));
	for (int i = 0; i < n; i++)
	{
		dp[i] = calloc(n, sizeof(long long));
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	printf("%lld\n", dp[n - 1][k - 1]);

	for (int i = 0; i < n; i++)
		free(dp[i]);
	free(dp);

	return 0;
}
