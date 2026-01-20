#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	if (scanf("%d", &n) != 1)
		return 0;

	int *pos = (int *)malloc((n + 1) * sizeof(int));
	if (!pos)
		return 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		pos[x] = i;
	}

	int cnt = 0;
	for (int v = 2; v <= n; v++)
	{
		if (pos[v] < pos[v - 1])
			cnt++;
	}

	printf("%d", cnt);

	free(pos);
	return 0;
}
