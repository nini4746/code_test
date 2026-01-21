// 백준 9655번: 돌을 1개 또는 3개씩 가져갈 때 승자 판정

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	
	scanf("%d", &n);

	if (n % 2 == 0)
		printf("CY");
	else
		printf("SK");
}
