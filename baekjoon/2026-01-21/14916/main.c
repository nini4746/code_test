#include <stdio.h>

int main(void)
{
    int n;
    int cnt;
    int five;

    if (scanf("%d", &n) != 1)
        return 0;

    cnt = 0;
    five = n / 5;

    while (five >= 0)
    {
        int rest;

        rest = n - five * 5;
        if (rest % 2 == 0)
        {
            cnt = five + (rest / 2);
            printf("%d\n", cnt);
            return 0;
        }
        five--;
    }

    printf("-1\n");
    return 0;
}
