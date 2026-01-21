// 백준 30802번: 티셔츠 패키지와 펜 묶음 배분 수량 계산 후 남은 인원 나눔

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int n;

    scanf("%d", &n);

    int size[6] = {0};

    for (int i = 0; i < 6; i++)
        scanf("%d", &size[i]);
    
    int t, q;

    scanf("%d %d", &t, &q);

    int sum = 0;
    
    for (int i = 0; i < 6; i++)
    {
        sum += size[i] / t;
        
        if (size[i] % t != 0)
            sum++;
    }

    printf("%d\n",sum);
    printf("%d %d",n / q, n % q);
}
