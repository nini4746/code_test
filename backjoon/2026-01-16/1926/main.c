// 백준 1926번: 그림의 개수와 각 그림 넓이를 BFS/DFS로 세기

#include <stdio.h>
#include <stdlib.h>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int **arr, int **visited, int n, int m, int r, int c)
{
	int area = 1;

	visited[r][c] = 1;

	for (int d = 0; d < 4; d++)
	{
		int nr = r + dx[d];
		int nc = c + dy[d];

		if (nr < 0 || nr >= n || nc < 0 || nc >= m)
			continue;
		if (visited[nr][nc])
			continue;
		if (arr[nr][nc] == 0)
			continue;
		
		area += dfs(arr, visited, n, m, nr, nc);
	}

	return area;

}

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);

	int **arr = calloc(n, sizeof(int *));
	int **visited = calloc(n, sizeof(int *));


	for (int i = 0; i < n; i++)
	{
		arr[i] = calloc(m, sizeof(int));
		visited[i] = calloc(m, sizeof(int));
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	}

	int count = 0;
    int max_area = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j] == 1 && !visited[i][j])
			{
				int area = dfs(arr, visited, n, m, i, j);
				count++;
				if (area > max_area)
					max_area = area;
			}
		}
	}

	printf("%d\n%d", count, max_area);
}
