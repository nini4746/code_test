// 백준 30456번: 길이 l인 수에서 앞 l-1자리를 1로, 마지막 자리를 n으로 채워 출력

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n, l;

    scanf("%d %d", &n, &l);

    for (int i = 0; i < l - 1; i++)
    {
        printf("1");
    }
    printf("%d", n);
}
