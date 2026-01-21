// 백준 1788번: 음수까지 포함한 피보나치 수를 mod 1,000,000,000으로 출력

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int sign;
	int abs_n;
	int *dp;

	if (n > 0)
		sign = 1;
	else if (n == 0)
		sign = 0;
	else
	{
		abs_n = -n;
		if (abs_n % 2 == 0)
			sign = -1;
		else
			sign = 1;
	}

	printf("%d\n", sign);

	if (n < 0)
		n = -n;

	dp = calloc(n + 1, sizeof(int));

	if (n == 0)
		dp[0] = 0;
	else
	{
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}

	printf("%d", dp[n]);

	free(dp);
}

/*
1	-	1
0	-	0
-1	-	1
-2	-	-1
-3	-	+2
-4	-	-3
-5	-	+5
-6	-	-8
*/
