// 백준 1292번: 1 2 2 3 3 3 … 수열에서 구간 합 구하기

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	int *arr = calloc(b, sizeof(int));

	int n = 0;
	for (int i = 0; n < b; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (n == 0)
				arr[n] = i;
			else
				arr[n] = i + arr[n - 1];
			n++;
		}
	}
	if (a == 1)
		printf("%d", arr[b - 1]);
	else
		printf("%d", arr[b - 1] - arr[a - 2]);
}
