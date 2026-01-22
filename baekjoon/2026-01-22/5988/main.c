#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	char s[110];

	if (scanf("%d", &n) != 1)
		return 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		char last = s[strlen(s) - 1];

		if (last % 2 == 0)
			puts("even");
		else
			puts("odd");
	}
	return 0;
}
