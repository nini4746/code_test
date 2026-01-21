// 백준 13301번: 피보나치 규칙으로 늘어나는 타일 테두리 길이 합 구하기

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	long long *dp = calloc(n + 2, sizeof(long long));

	dp[1] = 4;
	dp[2] = 6;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	printf("%lld", dp[n]);
}
