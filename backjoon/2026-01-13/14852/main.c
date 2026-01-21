// 백준 14852번: 2×n 보드를 여러 타일로 채우는 경우의 수 구하기

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int main(void)
{
	int n;
	scanf("%d", &n);

	long long *dp = calloc(n + 2, sizeof(long long));
	long long *s  = calloc(n + 2, sizeof(long long));

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;

	s[0] = 0;
	s[1] = 0;
	s[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2] + 2 * s[i - 1]) % MOD;

		s[i]  = (s[i - 1] + dp[i - 2]) % MOD;
	}

	printf("%lld\n", dp[n]);

	free(dp);
	free(s);
	return 0;
}
