#include <stdio.h>
#include <stdlib.h>

int n, m;
int arr[8];
int seq[8];
int visited[8];

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

void dfs(int depth)
{
	int i;

	if (depth == m)
	{
		for (i = 0; i < m; i++)
			printf("%d ", seq[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		seq[depth] = arr[i];
		dfs(depth + 1);
		visited[i] = 0;
	}
}

int main(void)
{
	int i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), cmp);
	dfs(0);
	return (0);
}
