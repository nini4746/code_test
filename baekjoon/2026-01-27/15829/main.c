#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	
	scanf("%d", &n);

	long long r = 1;
	long long m = 1234567891;

	char *str = calloc(n + 2, sizeof(char));
	scanf("%s", str);
	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		ans = (ans + (str[i] - 'a' + 1) * r) % m;
		r = (r * 31) % m;
	}

	printf("%lld", ans);
}