#include "binary_trees.h"

/**
 * binary_tree_nodes - this returns # of nodes in a tree with children
 * @tree: tree involved
 * Return: total of nodes and all involved children
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  n;

	n = 0;

	if (tree == NULL)
	{
		return (0);
	}
	{
		n += ((tree->left || tree->right) ? 1 : 0);
		n += binary_tree_nodes(tree->left);
		n += binary_tree_nodes(tree->right);
		return (n);
	}
}
