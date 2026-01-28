#include <stdio.h>

int main(void)
{
	int n;
	int x;
	int cur;
	int best;

	scanf("%d", &n);

	scanf("%d", &x);
	cur = x;
	best = x;

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &x);

		if (cur + x > x)
			cur = cur + x;
		else
			cur = x;

		if (cur > best)
			best = cur;
	}

	printf("%d\n", best);
	return 0;
}
