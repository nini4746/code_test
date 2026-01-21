// 백준 11659번: 1차원 배열의 구간 합을 여러 번 빠르게 질의

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	int *arr = calloc(n, sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		if (i == 0)
			arr[i] = val;
		else
			arr[i] = arr[i - 1] + val;
	}

	for (int i = 0; i < m; i++)
	{
		int a,b;

		scanf("%d %d", &a, &b);

		if (a == 1)
			printf("%d\n", arr[b - 1]);
		else
			printf("%d\n", arr[b - 1] - arr[a - 2]);
	}
}
