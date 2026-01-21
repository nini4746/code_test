// 백준 1904번: 00과 1 타일로 길이 n을 채우는 경우의 수

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int n;

	scanf("%d", &n);

	long long *dp = calloc(n, sizeof(long long ));

	dp[0] = 1;
	if (n == 1)
	{
		printf("%lld", dp[n - 1] % 15746);
		return 0;
	}
	dp[1] = 2;
	if (n == 2)
	{
		printf("%lld", dp[n - 1] % 15746);
		return 0;
	}
	for (int i = 2; i < n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	
	printf("%lld", dp[n - 1]);
}
