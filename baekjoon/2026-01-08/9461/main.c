// 백준 9461번: 파도반 수열의 n번째 값 계산

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int t;
	int max = 100;
	scanf("%d", &t);

	long long	*dp = calloc(max, sizeof(long long));

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < max; i++)
		dp[i] = dp[i - 3] + dp[i - 2];

	for (int i = 0; i < t; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%lld\n", dp[a - 1]);
	}
}
