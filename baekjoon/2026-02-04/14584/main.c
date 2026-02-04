#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(char *src, char *dst, int shift)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = (src[i] - 'a' - shift + 26) % 26 + 'a';
		i++;
	}
	dst[i] = '\0';
}

int contains_dict_word(char *text, char dict[][21], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (strstr(text, dict[i]) != NULL)
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	char cipher[101];
	int n;
	char dict[20][21];
	char decoded[101];
	int shift;

	scanf("%s", cipher);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s", dict[i]);

	shift = 0;
	while (shift < 26)
	{
		decrypt(cipher, decoded, shift);

		if (contains_dict_word(decoded, dict, n))
		{
			printf("%s\n", decoded);
			break;
		}
		shift++;
	}
	return (0);
}
