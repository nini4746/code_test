// 백준 11660번: 2차원 배열의 구간 합을 빠르게 질의

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int **arr = calloc(n, sizeof(int *));
	if (!arr)
		return (1);

	for (int i = 0; i < n; i++)
	{
		arr[i] = calloc(n, sizeof(int));
		if (!arr[i])
			return (1);

		for (int j = 0; j < n; j++)
		{
			int input;
			scanf("%d", &input);

			if (j == 0)
				arr[i][j] = input;
			else
				arr[i][j] = arr[i][j - 1] + input;
		}
	}

	while (m--)
	{
		int x1, y1, x2, y2;
		int ans = 0;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int r = x1 - 1; r <= x2 - 1; r++)
		{
			if (y1 == 1)
				ans += arr[r][y2 - 1];
			else
				ans += arr[r][y2 - 1] - arr[r][y1 - 2];
		}
		printf("%d\n", ans);
	}

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

	return (0);
}
