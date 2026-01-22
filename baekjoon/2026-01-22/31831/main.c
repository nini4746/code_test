#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	long long sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		long long val;
		scanf("%lld", &val);
		sum += val;
		if(sum >= m)
			cnt++;
		if (sum < 0)
			sum = 0;
	}
	printf("%d", cnt);
}