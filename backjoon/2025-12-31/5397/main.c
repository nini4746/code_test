#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char value;
	struct node *prev;
	struct node *next;
} node;

node *new_node(char value)
{
	node *n = malloc(sizeof(node));
	n->value = value;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		char str[1000001];
		scanf("%s", str);

		node *root = new_node(0);
		node *cursor = root;

		for (int i = 0; str[i]; i++)
		{
			if (str[i] == '<')
			{
				if (cursor->prev)
					cursor = cursor->prev;
			}
			else if (str[i] == '>')
			{
				if (cursor->next)
					cursor = cursor->next;
			}
			else if (str[i] == '-')
			{
				if (cursor != root)
				{
					node *del = cursor;
					cursor = cursor->prev;
					cursor->next = del->next;
					if (del->next)
						del->next->prev = cursor;
					free(del);
				}
			}
			else
			{
				node *n = new_node(str[i]);
				n->next = cursor->next;
				n->prev = cursor;
				if (cursor->next)
					cursor->next->prev = n;
				cursor->next = n;
				cursor = n;
			}
		}

		node *cur = root->next;
		while (cur)
		{
			printf("%c", cur->value);
			cur = cur->next;
		}
		printf("\n");

		while (root)
		{
			node *tmp = root;
			root = root->next;
			free(tmp);
		}
	}
	return 0;
}
