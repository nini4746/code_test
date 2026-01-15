#include <stdio.h>
#include <stdlib.h>

int run(int *arr, int pos, int sum, int target, int n)
{
	int cnt;

	if (pos == n)
		return (sum == target);
	cnt = 0;
	cnt += run(arr, pos + 1, sum + arr[pos], target, n);
	cnt += run(arr, pos + 1, sum, target, n);
	return cnt;
}

int main(void)
{
	int n;
	int s;
	int *arr;
	int result;

	scanf("%d %d", &n, &s);
	arr = calloc(n, sizeof(int));
	if (!arr)
		return (1);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	result = run(arr, 0, 0, s, n);
	if (s == 0)
		result -= 1;
	printf("%d", result);
	free(arr);
	return (0);
}
