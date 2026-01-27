#include <stdio.h>

int main(void)
{
	long long n;
	long long cnt = 0;

	scanf("%lld", &n);

	while (n > 0)
	{
		n /= 5;
		cnt += n;
	}

	printf("%lld\n", cnt);
	return 0;
}
