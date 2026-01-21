// 백준 15649번: 1..N 중복 없이 길이 M 순열을 사전순 출력

#include <stdio.h>
#include <stdlib.h>

int check(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[n] == arr[i])
            return 0;
    }
    return (1);
}

void run(int *arr, int size, int m, int start)
{
    if (start == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ",arr[i]);
        printf("\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        arr[start] = i + 1;
        if (!check(arr, start))
            continue;
        run (arr, size, m, start + 1);
    }
}

int main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    int *arr = calloc(m, sizeof(int));
    
    run(arr, n, m, 0);
}
