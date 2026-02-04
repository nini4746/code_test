#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int m, n, k;
int board[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int sy, int sx)
{
	int qy[10000];
	int qx[10000];
	int front, rear;
	int area;

	front = 0;
	rear = 0;
	area = 0;

	visited[sy][sx] = 1;
	qy[rear] = sy;
	qx[rear] = sx;
	rear++;

	while (front < rear)
	{
		int y = qy[front];
		int x = qx[front];
		front++;
		area++;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;
			if (visited[ny][nx])
				continue;
			if (board[ny][nx] == 1)
				continue;

			visited[ny][nx] = 1;
			qy[rear] = ny;
			qx[rear] = nx;
			rear++;
		}
	}
	return area;
}

int cmp_int(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;
	return (x - y);
}

int main(void)
{
	scanf("%d %d %d", &m, &n, &k);

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				board[y][x] = 1;
			}
		}
	}

	int areas[10000];
	int cnt = 0;

	for (int y = 0; y < m; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x] && board[y][x] == 0)
			{
				areas[cnt] = bfs(y, x);
				cnt++;
			}
		}
	}

	qsort(areas, cnt, sizeof(int), cmp_int);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", areas[i]);
	}
	printf("\n");

	return 0;
}
