// 백준 1764번: 듣도 못한/보도 못한 이름의 교집합을 정렬해 출력

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void *a, const void *b)
{
    return strcmp(*(char * const *)a, *(char * const *)b);
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    char **arr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(21);
        scanf("%20s", arr[i]);
    }

    char **arr_m = (char **)malloc(sizeof(char *) * m);
    for (int i = 0; i < m; i++)
    {
        arr_m[i] = (char *)malloc(21);
        scanf("%20s", arr_m[i]);
    }

    qsort(arr, n, sizeof(char *), cmp_str);
    qsort(arr_m, m, sizeof(char *), cmp_str);

    int cap = (n < m) ? n : m;
    char **res = (char **)malloc(sizeof(char *) * cap);
    int cnt = 0;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        int c = strcmp(arr[i], arr_m[j]);

        if (c == 0)
        {
            res[cnt] = (char *)malloc(21);
            strcpy(res[cnt], arr[i]);
            cnt++;
            i++;
            j++;
        }
        else if (c < 0)
            i++;
        else
            j++;
    }

    printf("%d\n", cnt);
    for (int k = 0; k < cnt; k++)
        printf("%s\n", res[k]);
    for (int k = 0; k < n; k++)
        free(arr[k]);
    for (int k = 0; k < m; k++)
        free(arr_m[k]);
    for (int k = 0; k < cnt; k++)
        free(res[k]);
    free(arr);
    free(arr_m);
    free(res);

    return 0;
}
