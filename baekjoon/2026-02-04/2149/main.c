#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_key
{
	char c;
	int  index;
}	t_key;

int cmp(const void *a, const void *b)
{
	t_key *k1 = (t_key *)a;
	t_key *k2 = (t_key *)b;

	if (k1->c != k2->c)
		return (k1->c - k2->c);
	return (k1->index - k2->index);
}

int main(void)
{
	char key[11];
	char cipher[101];
	int n, rows;
	t_key order[10];
	char matrix[10][100];   // 최대 10열 × 100행
	char result[101];

	scanf("%s", key);
	scanf("%s", cipher);

	n = strlen(key);
	rows = strlen(cipher) / n;

	for (int i = 0; i < n; i++)
	{
		order[i].c = key[i];
		order[i].index = i;
	}

	qsort(order, n, sizeof(t_key), cmp);

	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < rows; r++)
		{
			matrix[order[i].index][r] = cipher[pos++];
		}
	}

	pos = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < n; c++)
		{
			result[pos++] = matrix[c][r];
		}
	}
	result[pos] = '\0';

	printf("%s\n", result);
	return 0;
}
