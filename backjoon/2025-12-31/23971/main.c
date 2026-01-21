// 백준 23971번: 세로 n, 가로 m 간격을 두고 앉을 수 있는 좌석 최대 개수 계산

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
