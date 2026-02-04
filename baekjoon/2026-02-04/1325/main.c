#include <stdio.h>
#include <stdlib.h>

#define MAXN 10001
#define MAXM 100001

int N, M;
int head[MAXN], to[MAXM], nxt[MAXM];
int visited[MAXN];
int queue[MAXN];

int main(void)
{
	int i;
	int A, B;
	int idx = 0;
	int maxv = 0;
	int result[MAXN];

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		head[i] = -1;

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &A, &B);
		to[idx] = A;
		nxt[idx] = head[B];
		head[B] = idx++;
	}

	for (i = 1; i <= N; i++)
	{
		int front = 0, rear = 0;
		int cnt = 0;
		int j;

		for (j = 1; j <= N; j++)
			visited[j] = 0;

		queue[rear++] = i;
		visited[i] = 1;

		while (front < rear)
		{
			int v = queue[front++];
			cnt++;

			for (j = head[v]; j != -1; j = nxt[j])
			{
				int u = to[j];
				if (!visited[u])
				{
					visited[u] = 1;
					queue[rear++] = u;
				}
			}
		}

		result[i] = cnt;
		if (cnt > maxv)
			maxv = cnt;
	}

	for (i = 1; i <= N; i++)
		if (result[i] == maxv)
			printf("%d ", i);

	return 0;
}
