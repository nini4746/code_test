#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE 2100

typedef struct s_bigint
{
	int val[BASE];
	int minus;
} t_bigint;

static t_bigint bigint_zero(void)
{
	t_bigint r;
	memset(&r, 0, sizeof(r));
	return r;
}

t_bigint bigint_from_str(const char *s)
{
	t_bigint r = bigint_zero();
	int len = strlen(s);
	int start = 0;

	if (s[0] == '-')
	{
		r.minus = 1;
		start = 1;
	}

	for (int i = len - 1; i >= start; i--)
		r.val[len - 1 - i] = s[i] - '0';

	return r;
}

void bigint_print(t_bigint a)
{
	int i = BASE - 1;

	while (i > 0 && a.val[i] == 0)
		i--;

	if (a.minus && !(i == 0 && a.val[0] == 0))
		printf("-");

	for (; i >= 0; i--)
		printf("%d", a.val[i]);
}

int bigint_abs_cmp(t_bigint a, t_bigint b)
{
	for (int i = BASE - 1; i >= 0; i--)
	{
		if (a.val[i] > b.val[i]) return 1;
		if (a.val[i] < b.val[i]) return -1;
	}
	return 0;
}

t_bigint bigint_abs_add(t_bigint a, t_bigint b)
{
	t_bigint r = bigint_zero();
	int carry = 0;

	for (int i = 0; i < BASE; i++)
	{
		int sum = a.val[i] + b.val[i] + carry;
		r.val[i] = sum % 10;
		carry = sum / 10;
	}
	return r;
}

t_bigint bigint_abs_sub(t_bigint a, t_bigint b)
{
	t_bigint r = bigint_zero();
	int borrow = 0;

	for (int i = 0; i < BASE; i++)
	{
		int x = a.val[i] - borrow - b.val[i];
		if (x < 0)
		{
			x += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		r.val[i] = x;
	}
	return r;
}

t_bigint bigint_add(t_bigint a, t_bigint b)
{
	t_bigint r;

	if (a.minus == b.minus)
	{
		r = bigint_abs_add(a, b);
		r.minus = a.minus;
		return r;
	}

	int cmp = bigint_abs_cmp(a, b);
	if (cmp == 0)
		return bigint_zero();

	if (cmp > 0)
	{
		r = bigint_abs_sub(a, b);
		r.minus = a.minus;
	}
	else
	{
		r = bigint_abs_sub(b, a);
		r.minus = b.minus;
	}
	return r;
}

t_bigint bigint_sub(t_bigint a, t_bigint b)
{
	b.minus ^= 1;
	return bigint_add(a, b);
}

t_bigint bigint_mul(t_bigint a, t_bigint b)
{
	t_bigint r = bigint_zero();

	for (int i = 0; i < BASE; i++)
	{
		if (a.val[i] == 0)
			continue;

		int carry = 0;
		for (int j = 0; j + i < BASE; j++)
		{
			long long cur =
				r.val[i + j]
				+ (long long)a.val[i] * b.val[j]
				+ carry;

			r.val[i + j] = (int)(cur % 10);
			carry = (int)(cur / 10);
		}
	}

	r.minus = a.minus ^ b.minus;
	return r;
}

int main(void)
{
	char sa[2100];
	char sb[2100];

	scanf("%s", sa);
	scanf("%s", sb);

	t_bigint A = bigint_from_str(sa);
	t_bigint B = bigint_from_str(sb);

	t_bigint add = bigint_add(A, B);
	t_bigint sub = bigint_sub(A, B);
	t_bigint mul = bigint_mul(A, B);

	bigint_print(add);
	printf("\n");
	bigint_print(sub);
	printf("\n");
	bigint_print(mul);

	return 0;
}
