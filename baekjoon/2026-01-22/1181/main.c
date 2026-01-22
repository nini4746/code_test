#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 51

int compare(const void *a, const void *b)
{
	const char *sa;
	const char *sb;
	int lena;
	int lenb;

	sa = *(const char * const *)a;
	sb = *(const char * const *)b;

	lena = strlen(sa);
	lenb = strlen(sb);

	if (lena > lenb)
		return 1;
	if (lena < lenb)
		return -1;
	return strcmp(sa, sb);
}

int main(void)
{
	int n;
	int cnt = 0;

	scanf("%d", &n);

	char **strs = calloc(n, sizeof(char *));

	for (int i = 0; i < n; i++)
	{
		char input[SIZE];
		int duplicate = 0;

		scanf("%s", input);

		for (int j = 0; j < cnt; j++)
		{
			if (strcmp(input, strs[j]) == 0)
			{
				duplicate = 1;
				break;
			}
		}

		if (duplicate)
			continue;

		strs[cnt] = calloc(SIZE, sizeof(char));
		strcpy(strs[cnt], input);
		cnt++;
	}

	qsort(strs, cnt, sizeof(char *), compare);

	for (int i = 0; i < cnt; i++)
		printf("%s\n", strs[i]);

	for (int i = 0; i < cnt; i++)
		free(strs[i]);
	free(strs);

	return 0;
}
