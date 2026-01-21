// 백준 4307번: 개미가 양끝으로 떨어질 최소/최대 시간 계산

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, m;
		
		scanf("%d %d", &n, &m);

		int max1 = -1;
		int max2 = -1;

		for (int j = 0; j < m; j++)
		{
			int pos;
			scanf("%d", &pos);
			if (n - pos > pos)
			{
				if (pos > max1)
					max1 = pos;
				if (n - pos > max2)
					max2 = n - pos;
			}
			else
			{
				if (n - pos > max1)
					max1= n - pos;
				if (pos > max2)
					max2 = pos;
			}
		}
		printf("%d %d\n", max1, max2);
	}
}
