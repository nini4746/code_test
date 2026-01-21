// 백준 21600번: 각 위치 높이 제한 내에서 쌓을 수 있는 계단의 최대 높이 구하기

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int n;
	int i;
	int ans;
	int prev;
	int cur;
	int x;

	scanf("%d", &n);

	ans = 0;
	prev = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (i == 0)
			cur = 1;
		else
			cur = MIN(prev + 1, x);
		if (cur > ans)
			ans = cur;
		prev = cur;
	}
	printf("%d", ans);
	return 0;
}

// int main(void)
// {
// 	int t;

// 	scanf("%d", &t);

// 	int *arr = calloc(t, sizeof(int));
// 	for (int i = 0; i < t; i++)
// 	{
// 		scanf("%d", &arr[i]);
// 	}

// 	int stair = -1;
// 	int tmp_stair = 0;
// 	for (int i = 0; i < t; i++)
// 	{
// 		tmp_stair = 1;
// 		for (int j = i + 1; j < t; j++)
// 		{
// 			tmp_stair++;
// 			if (tmp_stair > arr[j])
// 			{
// 				tmp_stair--;
// 				break;
// 			}
// 		}
// 		if (tmp_stair > stair)
// 			stair = tmp_stair;
// 	}
// 	printf("%d", stair);
// }
