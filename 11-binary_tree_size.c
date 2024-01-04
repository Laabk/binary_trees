#include "binary_trees.h"
/**
 * binary_tree_size - function that return the size of a tree
 * @tree: tree to check
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t si = 0;
	size_t ri = 0, le = 0;

	if (tree == NULL)
	{
		return (0);
	}
	{
		le = binary_tree_size(tree->left);
		ri = binary_tree_size(tree->right);
		si = ri + le + 1;
	}
	return (si);
}
