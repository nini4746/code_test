/*

문제
다음과 같이 정의된 수열이 있다.

D[1] = A
D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합
예를 들어 A=57, P=2일 때, 수열 D는 [57, 74(=52+72=25+49), 65, 61, 37, 58, 89, 145, 42, 20, 4, 16, 37, …]이 된다. 그 뒤에는 앞서 나온 수들(57부터가 아니라 58부터)이 반복된다.

이와 같은 수열을 계속 구하다 보면 언젠가 이와 같은 반복수열이 된다. 이때, 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 구하는 프로그램을 작성하시오. 위의 예에서는 [57, 74, 65, 61]의 네 개의 수가 남게 된다.

입력
첫째 줄에 A(1 ≤ A ≤ 9999), P(1 ≤ P ≤ 5)가 주어진다.

출력
첫째 줄에 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수를 출력한다.

예제 입력 1 
57 2
예제 출력 1 
4

*/

#include <stdio.h>
#include <string.h>

int power(int x, int p)
{
	int r = 1;
	while (p--)
		r *= x;
	return r;
}

int next_num(int n, int p)
{
	int sum = 0;

	while (n > 0)
	{
		sum += power(n % 10, p);
		n /= 10;
	}
	return sum;
}

int main(void)
{
	int A, P;
	int visited[300000];
	int idx = 0;
	int cur;

	scanf("%d %d", &A, &P);

	memset(visited, -1, sizeof(visited));

	cur = A;
	while (visited[cur] == -1)
	{
		visited[cur] = idx++;
		cur = next_num(cur, P);
	}

	printf("%d\n", visited[cur]);
	return 0;
}
