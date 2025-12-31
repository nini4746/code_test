#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int h, w, n, m;

	scanf("%d %d %d %d",&h, &w, &n, &m);
	
	int x, y;

	x = (w - 1) / (m + 1) + 1;
	y = (h - 1) / (n + 1) + 1;

	printf("%d", x * y);
}