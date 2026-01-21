// 백준 1350번: 파일 크기와 블록 크기로 필요한 총 블록 수 계산

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	long long *arr = calloc(n, sizeof(long long));
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	long long size;
	long long ans = 0;

	scanf("%lld", &size);

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
			continue;
		if (arr[i] % size == 0)
			ans += arr[i] / size;
		else
			ans += arr[i] / size + 1;
	}

	printf("%lld", ans * size);
}
