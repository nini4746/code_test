#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	return (a > b ? a : b);
}

int main(void)
{
	int n;
	int m;
	int i;
	int j;
	int **map;
	int **dp;

	scanf("%d %d", &n, &m);

	map = (int **)calloc(n + 1, sizeof(int *));
	dp = (int **)calloc(n + 1, sizeof(int *));
	i = 0;
	while (i <= n)
	{
		map[i] = (int *)calloc(m + 1, sizeof(int));
		dp[i] = (int *)calloc(m + 1, sizeof(int));
		i++;
	}

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= m)
		{
			scanf("%d", &map[i][j]);
			j++;
		}
		i++;
	}

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= m)
		{
			dp[i][j] = map[i][j] + 
				max(dp[i-1][j], 
					max(dp[i][j-1], dp[i-1][j-1]));
			j++;
		}
		i++;
	}

	printf("%d\n", dp[n][m]);

	i = 0;
	while (i <= n)
	{
		free(map[i]);
		free(dp[i]);
		i++;
	}
	free(map);
	free(dp);

	return (0);
}
