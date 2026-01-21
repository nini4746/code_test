// 백준 2178번: 미로에서 BFS로 최단 이동 칸 수 구하기

#include <stdio.h>
#include <stdlib.h>

typedef struct s_pos
{
    int x;
    int y;
}   t_pos;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    char **str = calloc(n, sizeof(char *));
    int **dist = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        str[i] = calloc(m + 1, sizeof(char));
        dist[i] = calloc(m, sizeof(int));
        scanf("%s", str[i]);
    }

    t_pos *q = calloc(n * m, sizeof(t_pos));
    int front = 0;
    int rear = 0;

    dist[0][0] = 1;
    q[rear++] = (t_pos){0, 0};

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (front < rear)
    {
        t_pos cur = q[front++];

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (str[ny][nx] == '0')
                continue;
            if (dist[ny][nx] != 0)
                continue;

            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            q[rear++] = (t_pos){nx, ny};
        }
    }

    printf("%d\n", dist[n - 1][m - 1]);

    for (int i = 0; i < n; i++)
    {
        free(str[i]);
        free(dist[i]);
    }
    free(str);
    free(dist);
    free(q);

    return 0;
}
