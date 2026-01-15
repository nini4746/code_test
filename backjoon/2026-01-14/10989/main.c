#include <stdio.h>

int main(void)
{
    int n;
    int cnt[10001] = {0};
    int x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int v = 1; v <= 10000; v++)
    {
        while (cnt[v]--)
            printf("%d\n", v);
    }

    return 0;
}
