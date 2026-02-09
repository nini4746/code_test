#include <stdio.h>
#include <stdlib.h>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

static int dfs(int x, int y, int n, int **map, int **visited)
{
	int size = 1;

	visited[x][y] = 1;
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (visited[nx][ny])
			continue;
		if (map[nx][ny] == 0)
			continue;

		size += dfs(nx, ny, n, map, visited);
	}
	return size;
}

static int cmp_int(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;

	return (x - y);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int **map = (int **)calloc(n, sizeof(int *));
	int **visited = (int **)calloc(n, sizeof(int *));
	char *line = (char *)malloc((size_t)n + 1);

	for (int i = 0; i < n; i++)
	{
		map[i] = (int *)calloc(n, sizeof(int));
		visited[i] = (int *)calloc(n, sizeof(int));

		scanf("%s", line);
		for (int j = 0; j < n; j++)
			map[i][j] = line[j] - '0';
	}

	int *sizes = NULL;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				int size = dfs(i, j, n, map, visited);

				int *tmp = (int *)realloc(sizes, sizeof(int) * (count + 1));
				if (!tmp)
				{
					free(sizes);
					for (int k = 0; k < n; k++)
					{
						free(map[k]);
						free(visited[k]);
					}
					free(map);
					free(visited);
					free(line);
					return 1;
				}
				sizes = tmp;
				sizes[count] = size;
				count++;
			}
		}
	}

	qsort(sizes, (size_t)count, sizeof(int), cmp_int);

	printf("%d\n", count);
	for (int i = 0; i < count; i++)
		printf("%d\n", sizes[i]);

	free(sizes);
	for (int i = 0; i < n; i++)
	{
		free(map[i]);
		free(visited[i]);
	}
	free(map);
	free(visited);
	free(line);

	return 0;
}
