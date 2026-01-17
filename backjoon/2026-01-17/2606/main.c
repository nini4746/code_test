#include <stdio.h>
#include <stdlib.h>

int bfs(int **map, int *visited, int v, int start)
{
	int *queue = calloc(v, sizeof(int));
	int front = 0;
	int rear = 0;
	int cnt = 0;

	queue[rear++] = start;
	visited[start] = 1;

	while (front < rear)
	{
		int now = queue[front++];

		for (int i = 0; i < v; i++)
		{
			if (map[now][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
				queue[rear++] = i;
				cnt++;
			}
		}
	}

	free(queue);
	return cnt;
}

int main(void)
{
	int v;
	int e;

	scanf("%d", &v);
	scanf("%d", &e);
	
	int **map = calloc(v, sizeof(int *));
	for (int i = 0; i < v; i++)
		map[i] = calloc(v, sizeof(int));
	for (int i = 0; i < e; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--;
		v2--;
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}

	int *visited = calloc(v, sizeof(int));
	int ans = bfs(map, visited, v, 0);
	printf("%d\n", ans);

	for (int i = 0; i < v; i++)
		free(map[i]);
	free(map);
	free(visited);
}
