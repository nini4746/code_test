#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    int *dpa = calloc(n, sizeof(int));
    int *dpb = calloc(n, sizeof(int));

    dpa[0] = 0;
    dpb[0] = 1;

    for (int i = 1; i < n; i++)
    {
        dpa[i] = dpb[i - 1];
        dpb[i] = dpa[i - 1] + dpb[i - 1];
    }
    printf("%d %d", dpa[n - 1], dpb[n - 1]);
}
