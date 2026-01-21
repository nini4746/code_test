// 백준 30020번: a, b 조건을 만족하면 'aba' 반복 형태로 a개의 a와 b개의 b를 포함한 문자열 구성

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;

    scanf("%d %d", &a, &b);

    if (a <= 2 * b && a >= b + 1)
    {
        printf("YES\n");
        printf("%d\n", a - b);
        while (a != (b + 1))
        {
            printf("aba\n");
            a -= 2;
            b -= 1;
        }
        printf("a");
        for (int i = 0; i < b; i++)
            printf("ba");
    }
    else
        printf("NO");

}
