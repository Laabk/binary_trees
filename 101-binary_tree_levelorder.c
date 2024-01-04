#include "binary_trees.h"
/**
 * the_binary_tree_height - this measures the height of a binary tree
 * @tree: tree involved
 * Return: height
 */
size_t the_binary_tree_height(const binary_tree_t *tree)
{
	size_t le = 0;
	size_t ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	{
		if (tree)
		{
			le = tree->left ? 1 + the_binary_tree_height(tree->left) : 0;
			ri = tree->right ? 1 + the_binary_tree_height(tree->right) : 0;
		}
		return ((le > ri) ? le : ri);
	}
}
/**
 * the_binary_tree_depth - the depth of the node position from root
 * @tree: the involved with the depth
 * Return: 0 for the root else number of depth
 */
size_t the_binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + the_binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - a linked list func from depth level and node
 * @head: head of linked list
 * @tree: node
 * @level: depth of node
 * Return: void
 */

void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *a;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		a = *head;
		while (a->next != NULL)
		{
			a = a->next;
		}
		new->next = NULL;
		a->next = new;
	}
}

/**
 * occur_recursive - the takes complete throught the tree and each stores each node
 * in linked_node function
 * @head: head of linked list
 * @tree: node involved
 * Return: void
 */
void occur_recursive(link_t **head, const binary_tree_t *tree)
{
	size_t lev = 0;

	if (tree != NULL)
	{
		lev = the_binary_tree_depth(tree);
		linked_node(head, tree, lev);
		occur_recursive(head, tree->left);
		occur_recursive(head, tree->right);
	}
}
/**
 * binary_tree_levelorder - this print nodes element in level-order
 * @tree: the root node
 * @func: the function
 * Return:void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *a;
	size_t h = 0, c = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		h = the_binary_tree_height(tree);
		head = NULL;
		occur_recursive(&head, tree);
		while (c <= h)
		{
			a = head;
			while (a != NULL)
			{
				if (c == a->n)
				{
					func(a->node->n);
				}
				a = a->next;
			}
			c++;
		}
		while (head != NULL)
		{
			a = head;
			head = head->next;
			free(a);
		}
	}
}
