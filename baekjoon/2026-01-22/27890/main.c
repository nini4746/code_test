#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x,n;

	scanf("%d %d", &x, &n);

	int ans = x;

	for (int i = 0; i < n; i++)
	{
		if (ans % 2 == 0)
			ans = (ans / 2) ^ 6;
		else
			ans = (ans * 2) ^ 6;
	}
	printf("%d", ans);
}