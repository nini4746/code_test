#include <stdio.h>
#include <stdlib.h>

#define MAX 105

int n;
char map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy, int colorblind)
{
	int queue[10001][2];
	int front = 0;
	int rear = 0;
	char current = map[sx][sy];

	queue[rear][0] = sx;
	queue[rear][1] = sy;
	rear++;

	visited[sx][sy] = 1;

	while (front < rear)
	{
		int x = queue[front][0];
		int y = queue[front][1];
		front++;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;

			if (!colorblind)
			{
				if (map[nx][ny] == current)
				{
					visited[nx][ny] = 1;
					queue[rear][0] = nx;
					queue[rear][1] = ny;
					rear++;
				}
			}
			else
			{
				if (current == 'B')
				{
					if (map[nx][ny] == 'B')
					{
						visited[nx][ny] = 1;
						queue[rear][0] = nx;
						queue[rear][1] = ny;
						rear++;
					}
				}
				else
				{
					if (map[nx][ny] == 'R' || map[nx][ny] == 'G')
					{
						visited[nx][ny] = 1;
						queue[rear][0] = nx;
						queue[rear][1] = ny;
						rear++;
					}
				}
			}
		}
	}
}

int count_regions(int colorblind)
{
	int count = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				bfs(i, j, colorblind);
				count++;
			}
		}
	}
	return count;
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);

	int normal = count_regions(0);
	int blind = count_regions(1);

	printf("%d %d\n", normal, blind);

	return 0;
}
