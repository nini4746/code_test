#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n;

		scanf("%d", &n);
		
		int *arr = calloc(n, sizeof(int));
		int *visited = calloc(n, sizeof(int));

		for (int j = 0; j < n; j++)
		{
			int val;
			scanf("%d", &val);
			arr[j] = val - 1;
		}

		int cnt = 0;
		
		for (int j = 0; j < n; j++)
		{
			if(!visited[j])
			{
				int cur = j;
				while(!visited[cur])
				{
					visited[cur] = 1;
					cur = arr[cur]; 
				}
				cnt++;
			}
		}
		printf("%d\n", cnt);
		free(arr);
		free(visited);
	}
}