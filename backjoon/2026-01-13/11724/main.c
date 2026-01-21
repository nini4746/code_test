// 백준 11724번: 무방향 그래프의 연결 요소 개수 세기

#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **map, int *vis)
{
	vis[v] = 1;
	for (int u = 0; u < n; u++)
	{
		if (map[v][u] && !vis[u])
			dfs(u, n, map, vis);
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int **map = calloc(n, sizeof(int *));
	for (int i = 0; i < n; i++)
		map[i] = calloc(n, sizeof(int));

	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		v1--; v2--;
		map[v1][v2] = 1;
		map[v2][v1] = 1;
	}

	int *vis = calloc(n, sizeof(int));
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			cnt++;
			dfs(i, n, map, vis);
		}
	}

	printf("%d\n", cnt);

	for (int i = 0; i < n; i++)
		free(map[i]);
	free(map);
	free(vis);
	return 0;
}
