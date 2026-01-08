#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;

	scanf("%d", &n);
	
	int dp0[41] = {0};
	int dp1[41] = {0};

	dp0[0] = 1;
	dp1[1] = 1;

	for (int i = 0; i <=40; i++)
	{
		dp0[i] = dp0[i - 2] + dp0[i - 1];
		dp1[i] = dp1[i - 2] + dp1[i - 1];
	}

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%d ", dp0[a]);
		printf("%d\n", dp1[a]);
	}
}
