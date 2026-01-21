// 백준 1271번: 큰 수의 나눗셈과 나머지 계산

#include <stdio.h>
#include <string.h>

typedef struct {
	int len;
	int d[1100];
} BigInt;

void trim(BigInt *a)
{
	while (a->len > 1 && a->d[0] == 0)
	{
		for (int i = 0; i < a->len - 1; i++)
			a->d[i] = a->d[i + 1];
		a->len--;
	}
}

BigInt from_str(char *s)
{
	BigInt a;
	a.len = strlen(s);
	for (int i = 0; i < a.len; i++)
		a.d[i] = s[i] - '0';
	return a;
}

int cmp(BigInt *a, BigInt *b)
{
	if (a->len != b->len)
		return (a->len > b->len);
	for (int i = 0; i < a->len; i++)
	{
		if (a->d[i] != b->d[i])
			return (a->d[i] > b->d[i]);
	}
	return 1;
}

void sub(BigInt *a, BigInt *b)
{
	int i = a->len - 1;
	int j = b->len - 1;

	while (j >= 0)
	{
		a->d[i] -= b->d[j];
		if (a->d[i] < 0)
		{
			a->d[i] += 10;
			a->d[i - 1]--;
		}
		i--;
		j--;
	}
	trim(a);
}

void shift_add(BigInt *a, int digit)
{
	a->d[a->len++] = digit;
	trim(a);
}

int main(void)
{
	char n_str[1100], m_str[1100];
	BigInt n, m, cur;
	int started = 0;

	scanf("%s %s", n_str, m_str);

	n = from_str(n_str);
	m = from_str(m_str);

	cur.len = 1;
	cur.d[0] = 0;

	for (int i = 0; i < n.len; i++)
	{
		shift_add(&cur, n.d[i]);
		int q = 0;

		while (cmp(&cur, &m))
		{
			sub(&cur, &m);
			q++;
		}

		if (q != 0 || started)
		{
			printf("%d", q);
			started = 1;
		}
	}

	if (!started)
		printf("0");

	printf("\n");

	for (int i = 0; i < cur.len; i++)
		printf("%d", cur.d[i]);

	printf("\n");
	return 0;
}
