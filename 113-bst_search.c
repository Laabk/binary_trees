#include "binary_trees.h"

/**
 * bst_search - this searches to find a value in a Binary Search Tree
 * @tree: pointer to the BST to search
 * @value: the value to search in the tree
 * Return: A pointer to the node containing an int equal to val
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (tree == NULL)
	return (NULL);

	while (node)
	{
	if (value == node->n)
	return (node);
	if (value < node->n)
	node = node->left;
	else if (value > node->n)
	node = node->right;
	}

	return (NULL);
}
