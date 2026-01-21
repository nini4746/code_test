// 백준 25487번: 여러 테스트케이스에서 세 정수의 최솟값 출력

#include <stdio.h>
#include <stdlib.h>

#define min(x,y) ((x) > (y) ? (y) : (x))

int main(void)
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		printf("%d\n", min(min(a, b), c));
	}
}
