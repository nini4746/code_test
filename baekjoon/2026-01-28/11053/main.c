#include <stdio.h>

int main(void)
{
	int n;
	int a[1000];
	int dp[1000];
	int ans;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	ans = 0;

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}

		if (dp[i] > ans)
			ans = dp[i];
	}

	printf("%d\n", ans);
	return 0;
}
