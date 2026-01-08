#include <stdio.h>
#include <string.h>

#define BASE 1000000000
#define MAXLEN 260

void add(int *a, int *b, int *c)
{
	long long carry = 0;
	for (int i = 0; i < MAXLEN; i++)
	{
		long long sum = (long long)a[i] + b[i] + carry;
		c[i] = sum % BASE;
		carry = sum / BASE;
	}
}

void print_bigint(int *a)
{
	int i = MAXLEN - 1;

	while (i > 0 && a[i] == 0)
		i--;

	printf("%d", a[i]);

	while (--i >= 0)
		printf("%09d", a[i]);

	printf("\n");
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int f0[MAXLEN] = {0};
	int f1[MAXLEN] = {0};
	int f2[MAXLEN] = {0};

	f1[0] = 1;

	if (n == 0)
	{
		printf("0\n");
		return 0;
	}
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		add(f0, f1, f2);
		memcpy(f0, f1, sizeof(f0));
		memcpy(f1, f2, sizeof(f1));
		memset(f2, 0, sizeof(f2));
	}

	print_bigint(f1);
	return 0;
}
