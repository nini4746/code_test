#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *a = calloc(n, sizeof(int));
	int *dp = calloc(n + 1, sizeof(int));
	if (!a || !dp)
		return 1;

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dp[n] = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int next = i + a[i] + 1;
		if (next >= n)
			dp[i] = 1;
		else
			dp[i] = 1 + dp[next];
	}

	for (int i = 0; i < n; i++)
		printf("%d ", dp[i]);

	free(a);
	free(dp);
	return 0;
}
