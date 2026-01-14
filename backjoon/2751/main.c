#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int i = *(const int *)a;
    int j = *(const int *)b;

    return (i - j);
}

int main(void)
{
    int n;

    scanf("%d", &n);

    int *arr = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}