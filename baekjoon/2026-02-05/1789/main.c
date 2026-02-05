#include <stdio.h>

int main(void)
{
	unsigned long long S;
	unsigned long long lo;
	unsigned long long hi;
	unsigned long long ans;

	if (scanf("%llu", &S) != 1)
		return 0;

	lo = 1;
	hi = 100000000ULL;
	ans = 0;

	while (lo <= hi)
	{
		unsigned long long mid;
		unsigned long long sum;

		mid = (lo + hi) / 2;
		sum = mid * (mid + 1) / 2;

		if (sum <= S)
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}

	printf("%llu\n", ans);
	return 0;
}
