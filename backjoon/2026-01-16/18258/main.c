#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    int n;

    scanf("%d", &n);

    int *queue = calloc(n, sizeof(int));

    int front = 0;
    int rear = 0;
    for (int i = 0; i < n; i++)
    {
        char cmd[10];

        scanf("%s", cmd);

        if(strcmp(cmd, "push") == 0)
        {   
            int val;
            scanf("%d", &val);
            
            queue[rear] = val; 
            rear++;
        }
        if(strcmp(cmd, "pop") == 0)
        {
            if (front < rear)
            {
                printf("%d\n",queue[front]);
                front++;
            }
            else
                printf("-1\n");
        }
        if(strcmp(cmd, "size") == 0)
        {
            printf("%d\n",rear - front);
        }
        if(strcmp(cmd, "empty") == 0)
        {
            if (front == rear)
                printf("1\n");
            else
                printf("0\n");
        }
        if(strcmp(cmd, "front") == 0)
        {
            if (front < rear)
            {
                printf("%d\n",queue[front]);
            }
            else
                printf("-1\n");          
        }
        if(strcmp(cmd, "back") == 0)
        {
            if (front < rear)
            {
                printf("%d\n",queue[rear - 1]);
            }
            else
                printf("-1\n");
        }
    }
}