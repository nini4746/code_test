// 백준 11057번: 0~9로 이루어진 오르막 수의 개수 DP로 계산

#include <stdio.h>

#define MOD 10007

int main(void)
{
	int n;
	int dp[10];
	int i;
	int j;

	scanf("%d", &n);

	i = 0;
	while (i < 10)
	{
		dp[i] = 1;
		i++;
	}

	i = 2;
	while (i <= n)
	{
		j = 1;
		while (j < 10)
		{
			dp[j] = (dp[j] + dp[j - 1]) % MOD;
			j++;
		}
		i++;
	}

	int ans;
	ans = 0;
	j = 0;
	while (j < 10)
	{
		ans = (ans + dp[j]) % MOD;
		j++;
	}

	printf("%d", ans);
	return 0;
}
