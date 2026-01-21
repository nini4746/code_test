// 백준 17175번: 피보나치 호출 횟수 DP (memoization 개수) 계산

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int n;
	
	scanf("%d", &n);

	long long *dp = calloc(n + 1, sizeof(long long));

	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + 1) % 1000000007;
	}
	printf("%lld", dp[n]);

	free(dp);
}

/*

0 = 1
1 = 1
2 = 3
3 = 5

*/
