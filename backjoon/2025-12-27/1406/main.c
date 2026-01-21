// 백준 1406번: 커서 이동/삽입/삭제 명령 후 최종 문자열 구하기

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    char c;
    struct s_node *prev;
    struct s_node *next;
} t_node;

t_node *new_node(char c)
{
    t_node *n = malloc(sizeof(t_node));
    n->c = c;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

int main(void)
{
    char str[100001];
    int n;
    char cmd, ch;

    scanf("%100000s", str);

    t_node *head = new_node(0);
    t_node *cursor = head;

    for (int i = 0; str[i]; i++)
    {
        t_node *n = new_node(str[i]);
        n->prev = cursor;
        cursor->next = n;
        cursor = n;
    }

    scanf("%d", &n);

    while (n--)
    {
        scanf(" %c", &cmd);

        if (cmd == 'L')
        {
            if (cursor != head)
                cursor = cursor->prev;
        }
        else if (cmd == 'D')
        {
            if (cursor->next)
                cursor = cursor->next;
        }
        else if (cmd == 'B')
        {
            if (cursor != head)
            {
                t_node *del = cursor;
                cursor = cursor->prev;
                cursor->next = del->next;
                if (del->next)
                    del->next->prev = cursor;
                free(del);
            }
        }
        else if (cmd == 'P')
        {
            scanf(" %c", &ch);
            t_node *n = new_node(ch);

            n->next = cursor->next;
            n->prev = cursor;
            if (cursor->next)
                cursor->next->prev = n;
            cursor->next = n;
            cursor = n;
        }
    }

    t_node *p = head->next;
    while (p)
    {
        printf("%c", p->c);
        t_node *tmp = p;
        p = p->next;
        free(tmp);
    }
    free(head);
    printf("\n");

    return 0;
}
