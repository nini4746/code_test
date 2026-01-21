// 백준 9372번: 국가가 n개일 때 여행에 필요한 최소 비행기 수는 n-1

#include <stdio.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
		}

		printf("%d\n", n - 1);
	}
	return 0;
}
