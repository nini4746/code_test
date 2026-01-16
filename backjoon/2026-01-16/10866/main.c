#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
    int val;
    struct s_node *next;
}t_node;

t_node *insert_node(int val)
{
    t_node *node = calloc(1, sizeof(t_node));
    node->val = val;
    node->next = NULL;
    return node;
}

int main(void)
{

    int n;

    scanf("%d", &n);

    t_node *front = NULL;
    t_node *back = NULL;
    int size = 0;

    for (int i = 0; i < n; i++)
    {
        char cmd[15];

        scanf("%s", cmd);

        if(strcmp(cmd, "push_front") == 0)
        {   
            int val;
            scanf("%d", &val);
            
            t_node *new_node = insert_node(val);
            if (front == NULL)
            {
                front = new_node;
                back = new_node;
            }
            else
            {
                new_node->next = front;
                front = new_node;
            }
            size++;
        }
        if(strcmp(cmd, "push_back") == 0)
        {   
            int val;
            scanf("%d", &val);
            
            t_node *new_node = insert_node(val);
            if (back == NULL)
            {
                front = new_node;
                back = new_node;
            }
            else
            {
                back->next = new_node;
                back = new_node;
            }
            size++;
        }
        if (strcmp(cmd, "pop_front") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else if (size == 1)
            {
                printf("%d\n", front->val);
                free(front);
                front = NULL;
                back = NULL;
                size--;
            }
            else
            {
                t_node *tmp = front;
                printf("%d\n", front->val);
                front = front->next;
                free(tmp);
                size--;
            }
        }
        if (strcmp(cmd, "pop_back") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else if (size == 1)
            {
                printf("%d\n", back->val);
                free(back);
                front = NULL;
                back = NULL;
                size--;
            }
            else
            {
                t_node *cur = front;

                while (cur->next != back)
                    cur = cur->next;

                printf("%d\n", back->val);
                free(back);
                back = cur;
                back->next = NULL;
                size--;
            }
        }
        if(strcmp(cmd, "size") == 0)
        {
            printf("%d\n", size);
        }
        if(strcmp(cmd, "empty") == 0)
        {
            if (size == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        if(strcmp(cmd, "front") == 0)
        {
            if(size > 0)
            {
                printf("%d\n", front->val);
            }
            else
                printf("-1\n");
        }
        if(strcmp(cmd, "back") == 0)
        {
            if(size > 0)
            {
                printf("%d\n", back->val);
            }
            else
                printf("-1\n"); 
        }
    }
}