#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int k;

	scanf("%d %d", &n, &k);

	int *arr = calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int cnt = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (k == 0)
			break;

		cnt += k / arr[i];
		k %= arr[i];
	}

	printf("%d\n", cnt);

	free(arr);
	return 0;
}
