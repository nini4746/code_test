#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 600
#define MAX_LEN 110

char fib[MAX][MAX_LEN];
int fib_count = 0;

void add(char *a, char *b, char *result)
{
	char temp[MAX_LEN];
	int len_a;
	int len_b;
	int i;
	int carry;
	int sum;
	int idx;

	len_a = strlen(a);
	len_b = strlen(b);
	carry = 0;
	idx = 0;

	i = 0;
	while (i < len_a || i < len_b || carry)
	{
		sum = carry;
		if (i < len_a)
			sum += a[len_a - 1 - i] - '0';
		if (i < len_b)
			sum += b[len_b - 1 - i] - '0';

		temp[idx] = (sum % 10) + '0';
		carry = sum / 10;
		idx++;
		i++;
	}

	for (i = 0; i < idx; i++)
		result[i] = temp[idx - 1 - i];

	result[idx] = '\0';
}

int cmp(char *a, char *b)
{
	int len_a;
	int len_b;

	len_a = strlen(a);
	len_b = strlen(b);

	if (len_a > len_b)
		return 1;
	if (len_a < len_b)
		return -1;
	return strcmp(a, b);
}

void init_fib()
{
	strcpy(fib[0], "1");
	strcpy(fib[1], "2");
	fib_count = 2;

	while (1)
	{
		add(fib[fib_count - 1], fib[fib_count - 2], fib[fib_count]);

		if (strlen(fib[fib_count]) > 101)
			break;

		fib_count++;
	}
}

int main(void)
{
	char a[MAX_LEN];
	char b[MAX_LEN];
	int i;
	int count;

	init_fib();

	while (1)
	{
		scanf("%s %s", a, b);

		if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
			break;

		count = 0;

		i = 0;
		while (i < fib_count)
		{
			if (cmp(fib[i], a) >= 0 && cmp(fib[i], b) <= 0)
				count++;
			i++;
		}

		printf("%d\n", count);
	}

	return 0;
}
