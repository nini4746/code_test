#include <stdio.h>
#include <stdlib.h>

typedef struct s_country
{
	int id;
	int gold;
	int silver;
	int bronze;
}	t_country;

int compare(const void *a, const void *b)
{
	const t_country *c1;
	const t_country *c2;

	c1 = (const t_country *)a;
	c2 = (const t_country *)b;

	if (c1->gold != c2->gold)
		return (c2->gold - c1->gold);
	if (c1->silver != c2->silver)
		return (c2->silver - c1->silver);
	if (c1->bronze != c2->bronze)
		return (c2->bronze - c1->bronze);
	return (0);
}

int main(void)
{
	int n;
	int k;
	t_country *arr;

	scanf("%d %d", &n, &k);

	arr = calloc(n, sizeof(t_country));

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d",
			&arr[i].id,
			&arr[i].gold,
			&arr[i].silver,
			&arr[i].bronze);
	}

	qsort(arr, n, sizeof(t_country), compare);

	int rank = 1;
	int same_count = 0;

	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			if (arr[i].gold == arr[i - 1].gold &&
				arr[i].silver == arr[i - 1].silver &&
				arr[i].bronze == arr[i - 1].bronze)
			{
				same_count++;
			}
			else
			{
				rank += same_count + 1;
				same_count = 0;
			}
		}

		if (arr[i].id == k)
		{
			printf("%d\n", rank);
			break;
		}
	}

	free(arr);
	return (0);
}
