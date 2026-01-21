// 백준 3273번: 두 수의 합이 x가 되는 서로 다른 쌍의 개수 구하기

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int n, x;
    int cnt = 0;

    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    qsort(arr, n, sizeof(int), cmp);

    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        int sum = arr[l] + arr[r];

        if (sum == x)
        {
            cnt++;
            l++;
            r--;
        }
        else if (sum < x)
            l++;
        else
            r--;
    }

    printf("%d\n", cnt);
    free(arr);
    return 0;
}
