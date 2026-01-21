#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    static int a[1500][1500];
    static int pos[1500];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
        pos[i] = n - 1;

    int ans = 0;

    for (int k = 0; k < n; k++)
    {
        int max = -2147483648;
        int idx = 0;

        for (int i = 0; i < n; i++)
        {
            if (pos[i] >= 0 && a[pos[i]][i] > max)
            {
                max = a[pos[i]][i];
                idx = i;
            }
        }

        ans = max;
        pos[idx]--;
    }

    printf("%d\n", ans);
    return 0;
}
