// 백준 18821번: t개 테스트마다 주어진 n의 홀짝을 E/O로 출력하는 문제 (미해결)

#include <stdio.h>

int main(void)
{
    int t, n;

    scanf("%d", &n);
    
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        if(n % 2 == 0)
            printf("E\n");
        else
            printf("O\n");
    }
}
