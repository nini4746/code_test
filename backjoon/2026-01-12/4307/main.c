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