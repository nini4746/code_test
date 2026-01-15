#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	int **arr = calloc(n, sizeof(int *));
	
	for (int i = 0; i < n; i++)
		arr[i] = calloc(n, sizeof(int));

	for (int i = 0; i < n - 1; i++)
	{
		int parent, child;

		scanf("%d %d", parent, child);

		parent--;
		child--;
		arr[child][parent] = 1;
	}
}