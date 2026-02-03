#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	char color[5];
	int num[5];
	int cnt[10] = {0};

	for (int i = 0; i < 5; i++)
	{
		scanf(" %c %d", &color[i], &num[i]);
		cnt[num[i]]++;
	}

	qsort(num, 5, sizeof(int), cmp);

	int same_color = 1;
	for (int i = 1; i < 5; i++)
	{
		if (color[i] != color[0])
			same_color = 0;
	}

	int is_straight = 1;
	for (int i = 0; i < 4; i++)
	{
		if (num[i] + 1 != num[i + 1])
			is_straight = 0;
	}

	int max = num[4];

	if (same_color && is_straight)
	{
		printf("%d\n", 900 + max);
		return 0;
	}

	int four = 0, three = 0, pair1 = 0, pair2 = 0;

	for (int i = 1; i <= 9; i++)
	{
		if (cnt[i] == 4)
			four = i;
		else if (cnt[i] == 3)
			three = i;
		else if (cnt[i] == 2)
		{
			if (!pair1)
				pair1 = i;
			else
				pair2 = i;
		}
	}

	if (four)
	{
		printf("%d\n", 800 + four);
		return 0;
	}

	if (three && (pair1 || pair2))
	{
		int pair = pair1 ? pair1 : pair2;
		printf("%d\n", 700 + three * 10 + pair);
		return 0;
	}

	if (same_color)
	{
		printf("%d\n", 600 + max);
		return 0;
	}

	if (is_straight)
	{
		printf("%d\n", 500 + max);
		return 0;
	}

	if (three)
	{
		printf("%d\n", 400 + three);
		return 0;
	}

	if (pair1 && pair2)
	{
		int big = pair1 > pair2 ? pair1 : pair2;
		int small = pair1 > pair2 ? pair2 : pair1;
		printf("%d\n", 300 + big * 10 + small);
		return 0;
	}

	/* 8. 원페어 */
	if (pair1)
	{
		printf("%d\n", 200 + pair1);
		return 0;
	}

	/* 9. 하이카드 */
	printf("%d\n", 100 + max);
	return 0;
}
