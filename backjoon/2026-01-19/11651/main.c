// 백준 11651번: 2차원 좌표를 y, x 순으로 정렬

#include <stdio.h>
#include <stdlib.h>

typedef struct s_pos
{
	int x;
	int y;
}t_pos;

int compare(const void *a, const void *b)
{
	const t_pos *x = (const t_pos *)a;
	const t_pos *y = (const t_pos *)b;

	if (x->y > y->y)
		return 1;
	if (x->y == y->y)
	{
		if (x->x > y->x)
			return 1;
		else
			return -1;
	}
	if (x->y < y->y)
		return -1;
	return 0;	
}


int main(void)
{
	int n;

	scanf("%d", &n);

	t_pos *arr = calloc(n, sizeof(t_pos));

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);

	qsort(arr, n, sizeof(t_pos), compare);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
}
