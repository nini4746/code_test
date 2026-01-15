#include <stdio.h>
#include <stdlib.h>


void    dfs(int **map, int *visited, int from, int size)
{
    visited[from] = 1;
    printf("%d ", from + 1);

    for (int i =0; i < size ; i++)
    {
        if (map[from][i] && !visited[i])
            dfs(map, visited, i, size);
    }
}


void    bfs(int **map, int *visited, int from, int size)
{
    int front = 0;
    int rear = 0;

    visited[from] = 1;
    int *queue = calloc(size, sizeof(int));
    queue[rear++] = from;
    while (front < rear)
    {   
        from = queue[front++];
        printf("%d ", from + 1);
        for (int i = 0; i < size; i++)
        {
            if (map[from][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main(void)
{
    int n , m, v;
    
    scanf("%d %d %d", &n, &m, &v);
    int **map = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        map[i] = calloc(n, sizeof(int));

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        map[v1 - 1][v2 - 1] = 1;
        map[v2 - 1][v1 - 1] = 1;
    }

    
    int *visited = calloc(n, sizeof(int));

    dfs(map, visited, v - 1, n);
    printf("\n");

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    bfs(map, visited, v - 1, n);
    printf("\n");

    for (int i = 0; i < n; i++)
        free(map[i]);
    free(map);
    free(visited);

    return (0);
}