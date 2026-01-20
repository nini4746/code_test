#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int *type = calloc(n, sizeof(int));
	int *arr  = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &type[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int m;
	scanf("%d", &m);

	int *q = calloc(n + m + 1, sizeof(int));
	int front = 0;
	int rear = 0;

	for (int i = n - 1; i >= 0; i--)
		if (type[i] == 0)
			q[rear++] = arr[i];

	for (int i = 0; i < m; i++)
	{
		int val;
		scanf("%d", &val);

		if (front < rear)
		{
			printf("%d ", q[front]);
			q[rear++] = val;
			front++;
		}
		else
			printf("%d ", val);
	}

	free(type);
	free(arr);
	free(q);
	return 0;
}
