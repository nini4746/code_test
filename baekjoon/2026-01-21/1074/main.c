#include <stdio.h>

int main(void)
{
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);

	int ans = 0;
	int size = 1 << N;

	while (size > 1)
	{
		int half = size / 2;

		if (r < half && c < half);
		else if (r < half && c >= half)
		{
			ans += half * half;
			c -= half;
		}
		else if (r >= half && c < half)
		{
			ans += half * half * 2;
			r -= half;
		}
		else
		{
			ans += half * half * 3;
			r -= half;
			c -= half;
		}

		size = half;
	}

	printf("%d\n", ans);
	return 0;
}
