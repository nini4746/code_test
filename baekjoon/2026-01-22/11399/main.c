#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;

	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int main(void)
{
	int	n;

	scanf("%d", &n);

	int	*arr = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	int sum = 0;
	int total = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		total += sum;
	}

	printf("%d", total);

	free(arr);
	return 0;
}