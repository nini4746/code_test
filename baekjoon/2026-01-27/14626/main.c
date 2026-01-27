	#include <stdio.h>

	int main(void)
	{
		char s[20];
		int i;
		int pos;
		int sum;
		int w;
		int t;
		int x;

		scanf("%s", s);

		pos = -1;
		sum = 0;

		for (i = 0; i < 13; i++)
		{
			if (s[i] == '*')
			{
				pos = i;
				continue;
			}

			if (i % 2 == 0)
				w = 1;
			else
				w = 3;

			sum += (s[i] - '0') * w;
		}
		sum %= 10;
		if (pos % 2 == 0)
			w = 1;
		else
			w = 3;
		t = (10 - sum) % 10;
		if (w == 1)
			x = t;
		else
			x = (7 * t) % 10;
		printf("%d\n", x);
		return 0;
	}
