#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    int max_len = 0;

    char **arr = calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = calloc(51, sizeof(char));
        scanf("%s",&arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ()
        }
    }
}