#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	char **strs = calloc(n, sizeof(char *));
	for (int i = 0; i < n; i++)
	{
		strs[i] = calloc(11, sizeof(char));
		scanf("%s", strs[i]);
	}

	int dive1 = 0;
	int dive2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (strcmp(strs[i], "KBS1") == 0)
		{
			while (dive1-- > 0)
				printf("4");
			break;
		}

		if (strcmp(strs[i], "KBS2") == 0)
			dive2 = 1;

		printf("1");
		dive1++;
	}

	if (dive2 == 1)
		printf("1");

	for (int i = 0; i < n; i++)
	{
		if (strcmp(strs[i], "KBS2") == 0)
		{
			while (dive2-- > 1)
				printf("4");
			break;
		}
		printf("1");
		dive2++;
	}

	return 0;
}
