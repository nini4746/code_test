#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	char			value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

t_node	*new_node(char v)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = v;
	n->left = NULL;
	n->right = NULL;
	return (n);
}

void preorder(t_node *root)
{
	if (root == NULL)
		return ;
	printf("%c", root->value);
	preorder(root->left);
	preorder(root->right);
}

void inorder(t_node *root)
{
	if (root == NULL)
		return ;
	inorder(root->left);
	printf("%c", root->value);
	inorder(root->right);
}

void postorder(t_node *root)
{
	if (root == NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->value);
}

t_node	*search(t_node *root, char c)
{
	t_node	*ret;

	if (root == NULL)
		return (NULL);
	if (root->value == c)
		return (root);
	ret = search(root->left, c);
	if (ret != NULL)
		return (ret);
	return (search(root->right, c));
}

int	main(void)
{
	int		n;
	t_node	*root;
	t_node	*ptr;
	t_node	*child;
	char	p, l, r;

	scanf("%d", &n);

	root = NULL;
	ptr = NULL;

	for (int i = 0; i < n; i++)
	{
		scanf(" %c %c %c", &p, &l, &r);

		if (root == NULL)
		{
			root = new_node(p);
			ptr = root;
		}
		else
			ptr = search(root, p);

		if (l != '.')
		{
			child = search(root, l);
			if (child == NULL)
				child = new_node(l);
			ptr->left = child;
		}
		else
			ptr->left = NULL;

		if (r != '.')
		{
			child = search(root, r);
			if (child == NULL)
				child = new_node(r);
			ptr->right = child;
		}
		else
			ptr->right = NULL;
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	return (0);
}
