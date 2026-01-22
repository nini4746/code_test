#include <stdio.h>

int main(void)
{
	char s[100001];

	int len;
	scanf("%d", &len);
	scanf("%s", s);

	for(int i = len - 5; i < len; i++)
		printf("%c", s[i]);
}
