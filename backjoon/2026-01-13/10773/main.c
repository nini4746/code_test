// 백준 10773번: 0이 나오면 직전 수를 지우며 합을 구하는 스택 시뮬레이션

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	int *stack = calloc(n, sizeof(int));
	int sum = 0;
	int top = -1;
	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		if (val == 0)
		{
			sum -= stack[top];
			stack[top--] = 0;
		}
		else
		{
			sum += val;
			stack[++top] = val;
		}
	}

	printf("%d", sum);
}
