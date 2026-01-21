// 백준 15489번: 파스칼 삼각형에서 (r,c) 시작, 한 변 길이 w인 정삼각형 영역 합 구하기

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);

	int size = r + w;

	long long **dp = calloc(size, sizeof(long long *));
	for (int i = 0; i < size; i++)
	{
		dp[i] = calloc(size, sizeof(long long));
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	long long sum = 0;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			sum += dp[r - 1 + i][c - 1 + j];
		}
	}

	printf("%lld\n", sum);

	for (int i = 0; i < size; i++)
		free(dp[i]);
	free(dp);

	return 0;
}
