// 백준 10610번: 주어진 숫자들로 30의 배수를 만들 수 있는지, 만들면 최댓값 출력

#include <stdio.h>
#include <string.h>

int main(void)
{
    char n[100001];
    int cnt[10];
    int sum;
    int len;

    for (int i = 0; i < 10; i++)
        cnt[i] = 0;
    sum = 0;

    scanf("%100000s", n);

    len = strlen(n);
    for (int i = 0; i < len; i++)
    {
        int d = n[i] - '0';
        cnt[d]++;
        sum += d;
    }

    if (cnt[0] == 0 || (sum % 3) != 0)
    {
        printf("-1");
        return 0;
    }

    for (int d = 9; d >= 0; d--)
    {
        while (cnt[d] > 0)
        {
            putchar('0' + d);
            cnt[d]--;
        }
    }
    return 0;
}
