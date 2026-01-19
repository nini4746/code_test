#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b)
{
	const char *sa;
	const char *sb;
	int lena;
	int lenb;
	int suma;
	int sumb;

	sa = *(const char * const *)a;
	sb = *(const char * const *)b;

	lena = strlen(sa);
	lenb = strlen(sb);

	if (lena != lenb)
		return (lena - lenb);

	suma = 0;
	sumb = 0;

	for (int i = 0; i < lena; i++)
	{
		if (isdigit(sa[i]))
			suma += sa[i] - '0';
	}
	for (int i = 0; i < lenb; i++)
	{
		if (isdigit(sb[i]))
			sumb += sb[i] - '0';
	}

	if (suma != sumb)
		return (suma - sumb);

	return strcmp(sa, sb);
}


int main(void)
{
	int n;

	scanf("%d", &n);

	char **arr = calloc(n, sizeof(char *));
	for (int i = 0; i < n; i++)
	{
		arr[i] = calloc(51, sizeof(char));
		scanf("%s", arr[i]);
	}

	qsort(arr, n, sizeof(char *), compare);

	for (int i = 0; i < n; i++)
		printf("%s\n", arr[i]);

	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);

	return 0;
}