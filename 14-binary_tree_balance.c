#include "binary_trees.h"

/**
 * binary_tree_height_b - this func measures the height of binary tree used
 * in bal tree
 * @tree: tree involved
 * Return: the height involved
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t le = 0, ri = 0;

	if (tree == NULL)
	{
		return (0);
	}
	{
		if (tree)
		{
			le = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			ri = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((le > ri) ? le : ri);
	}
}

/**
 * binary_tree_balance - this measures balance factor of a binary tree
 * @tree: treeinvolved
 * Return: the balanced factor of rthe node
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0, res = 0;

	if (tree)
	{
		left = ((int)binary_tree_height_b(tree->left));
		right = ((int)binary_tree_height_b(tree->right));
		res = left - right;
	}
	return (res);
}
