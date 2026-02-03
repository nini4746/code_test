#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int **arr;
	char *str;
	int row_cnt = 0;
	int col_cnt = 0;

	scanf("%d", &n);

	arr = calloc(n, sizeof(int *));
	str = calloc(n + 1, sizeof(char));

	for (int i = 0; i < n; i++)
	{
		arr[i] = calloc(n, sizeof(int));
		scanf("%s", str);
		for (int j = 0; j < n; j++)
		{
			if (str[j] == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
				cnt++;
			else
			{
				if (cnt >= 2)
					row_cnt++;
				cnt = 0;
			}
		}
		if (cnt >= 2)
			row_cnt++;
	}

	for (int j = 0; j < n; j++)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i][j] == 0)
				cnt++;
			else
			{
				if (cnt >= 2)
					col_cnt++;
				cnt = 0;
			}
		}
		if (cnt >= 2)
			col_cnt++;
	}

	printf("%d %d\n", row_cnt, col_cnt);

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	free(str);

	return (0);
}
