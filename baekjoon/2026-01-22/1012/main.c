#include <stdio.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void bfs(int start_x, int start_y, int m, int n, int *map, int *visited)
{
	const int dx[4] = {1, -1, 0, 0};
	const int dy[4] = {0, 0, 1, -1};

	t_point queue[2500];
	int front = 0;
	int rear = 0;

	queue[rear++] = (t_point){start_x, start_y};
	visited[start_x * n + start_y] = 1;

	while (front < rear)
	{
		t_point cur = queue[front++];

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			if (map[nx * n + ny] == 1 && visited[nx * n + ny] == 0)
			{
				visited[nx * n + ny] = 1;
				queue[rear++] = (t_point){nx, ny};
			}
		}
	}
}


int	main(void)
{
	int	t;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int	m, n, k;

		scanf("%d %d %d", &m, &n, &k);

		int *map = calloc((size_t)m * (size_t)n, sizeof(int));
		int *visited = calloc((size_t)m * (size_t)n, sizeof(int));
		if (!map || !visited)
		{
			free(map);
			free(visited);
			return 1;
		}

		for (int j = 0; j < k; j++)
		{
			int x, y;

			scanf("%d %d", &x, &y);
			map[x * n + y] = 1;
		}

		int ans = 0;

		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < n; y++)
			{
				int idx = x * n + y;

				if (map[idx] == 1 && visited[idx] == 0)
				{
					bfs(x, y, m, n, map, visited);
					ans++;
				}
			}
		}

		printf("%d\n", ans);

		free(map);
		free(visited);
	}
	return 0;
}
