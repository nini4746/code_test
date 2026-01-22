#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int *dead = calloc(n, sizeof(int));

	int cnt = 0;
	int pos = 0;

	printf("<");

	while (cnt < n)
	{
		int step = 0;

		while (step < k)
		{
			if (dead[pos] == 0)
				step++;
			if (step == k)
				break;
			pos = (pos + 1) % n;
		}

		dead[pos] = 1;
		printf("%d", pos + 1);
		cnt++;

		if (cnt < n)
			printf(", ");

		pos = (pos + 1) % n;
	}

	printf(">");
	free(dead);
}
