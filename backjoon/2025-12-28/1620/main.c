// 백준 1620번: 이름↔번호 포켓몬을 해시로 빠르게 조회

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 200003

typedef struct s_node
{
    char name[21];
    int idx;
    struct s_node *next;
} t_node;

unsigned long hash_str(const char *s)
{
    unsigned long h;

    h = 5381;
    while (*s)
    {
        h = ((h << 5) + h) + (unsigned char)(*s);
        s++;
    }
    return (h % TABLE_SIZE);
}

void insert_name(t_node **table, const char *name, int idx)
{
    unsigned long h;
    t_node *n;

    h = hash_str(name);
    n = (t_node *)malloc(sizeof(t_node));
    if (!n)
        exit(1);
    strcpy(n->name, name);
    n->idx = idx;
    n->next = table[h];
    table[h] = n;
}

int find_idx(t_node **table, const char *name)
{
    unsigned long h;
    t_node *p;

    h = hash_str(name);
    p = table[h];
    while (p)
    {
        if (strcmp(p->name, name) == 0)
            return (p->idx);
        p = p->next;
    }
    return (-1);
}

int is_number_str(const char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (!isdigit((unsigned char)s[i]))
            return (0);
        i++;
    }
    return (1);
}

char *dup_str(const char *s)
{
    size_t len;
    char *p;

    len = strlen(s);
    p = (char *)malloc(len + 1);
    if (!p)
        exit(1);
    memcpy(p, s, len + 1);
    return (p);
}

void free_table(t_node **table)
{
    int i;
    t_node *p;
    t_node *next;

    i = 0;
    while (i < TABLE_SIZE)
    {
        p = table[i];
        while (p)
        {
            next = p->next;
            free(p);
            p = next;
        }
        i++;
    }
}

int main(void)
{
    int n, m;
    char **by_idx;
    t_node **table;

    if (scanf("%d %d", &n, &m) != 2)
        return (0);

    by_idx = (char **)calloc((size_t)n + 1, sizeof(char *));
    table = (t_node **)calloc(TABLE_SIZE, sizeof(t_node *));
    if (!by_idx || !table)
        return (0);

    for (int i = 1; i <= n; i++)
    {
        char name[21];

        scanf("%20s", name);
        by_idx[i] = dup_str(name);
        insert_name(table, name, i);
    }

    while (m--)
    {
        char q[21];

        scanf("%20s", q);
        if (is_number_str(q))
            printf("%s\n", by_idx[atoi(q)]);
        else
            printf("%d\n", find_idx(table, q));
    }

    for (int i = 1; i <= n; i++)
        free(by_idx[i]);
    free(by_idx);

    free_table(table);
    free(table);

    return (0);
}
