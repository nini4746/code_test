#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);

	int *arr = calloc(m, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		arr[val - 1]++;
	}

	int max = 0;

	for (int i = 0; i < m; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("%d", max);
}