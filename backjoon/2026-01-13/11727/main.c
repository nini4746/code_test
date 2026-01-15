#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int n;

	scanf("%d", &n);

	int *dp = calloc(n + 2, sizeof(int));

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i < n; i++)
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007; 

	printf("%d", dp[n - 1]);
	free(dp);
}