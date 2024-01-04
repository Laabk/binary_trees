#include "binary_trees.h"
/**
 * leaf_node - this creates a leaf(new_node )in a linked_list
 * @node: pointer of node to be created
 * Return: node
 */
link_t *leaf_node(binary_tree_t *node)
{
	link_t *leaf;

	leaf =  malloc(sizeof(link_t));
	if (leaf == NULL)
	{
	return (NULL);
	}
	leaf->node = node;
	leaf->next = NULL;

	return (leaf);
}
/**
 * free_node - freeing the nodes at the linked list
 * @head: linked_list head
 * Return: void
 */
void free_node(link_t *head)
{
	link_t *curr;

	while (head)
	{
	curr = head->next;
	free(head);
	head = curr;
	}
}

/**
 * _push - fills the stack memory with a temp node
 * @node: pointer of node of the tree
 * @head: head node of in the stack
 * @tail: tail node of in the stack
 * Return: void
 */

void put_in_stack(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *all;

	all = leaf_node(node);
	if (all == NULL)
	{
		free_node(head);
		exit(1);
	}
	(*tail)->next = all;
	*tail = all;
}
/**
 * pop_node - this pops a node into the stack
 * @head: head node of in the stack
 */

void pop_node(link_t **head)
{
	link_t *curr;

	curr = (*head)->next;
	free(*head);
	*head = curr;
}

/**
 * binary_tree_is_complete - this checks if a binary tree is complete
 * @tree: pointer of node of the tree
 * Return: 1 if is complete 0 if it is not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int valid = 0;

	if (tree == NULL)
	{
	return (0);
	}
	head = tail = leaf_node((binary_tree_t *)tree);
	if (head == NULL)
	{
	exit(1);
	}
	while (head != NULL)
	{
	if (head->node->left != NULL)
	{
	if (valid == 1)
	{
	free_node(head);
	return (0);
	}
	put_in_stack(head->node->left, head, &tail);
	}
	valid = 1;
	if (head->node->right != NULL)
	{
	if (valid == 1)
	{
	free_node(head);
	return (0);
	}
	put_in_stack(head->node->right, head, &tail);
	}
	else
	valid = 1;
	pop_node(&head);
	}
	return (1);
}
