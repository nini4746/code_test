// 백준 2748번: 큰 n의 피보나치 수를 DP로 구하기

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
