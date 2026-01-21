// 백준 15688번: N(≤1,000,000)개의 수를 정렬하여 출력

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	int n;

	scanf("%d", &n);

	int *arr = calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}
